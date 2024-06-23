//
// Created by xiongxinlei on 5/28/24.
//
#include "bpe.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
#include "glog/logging.h"
namespace leomax_tokenizer {
namespace models {

const std::string WHITESPACE = " \n\r\t\f\v";

BPE::BPE() :
    fuse_unk_(false) {
}

BPE::BPE(const core::Vocab& vocab,
         const core::Merges& merges,
         size_t cache_capacity,
         const std::vector<float>& dropout,
         const std::vector<std::string>& unk_token,
         const std::vector<std::string>& continuing_subword_prefix,
         const std::vector<std::string>& end_of_word_suffix,
         bool fuse_unk) :
        vocab_(vocab),
        dropout_(dropout),
        unk_token_(unk_token),
        continuing_subword_prefix_(continuing_subword_prefix),
        end_of_word_suffix_(end_of_word_suffix),
        fuse_unk_(fuse_unk) {
    init(merges);
}

void BPE::init(const core::Merges& merges) {
    if (!dropout_.empty()) {
        if (dropout_[0] > 1.0 || dropout_[0] < 0.0) {
          throw std::runtime_error("dropout probability must be in range [0,1]");
        }
    }

    // 构建token id到token的映射关系
    for (auto& item: vocab_) {
        vocab_reversed_[item.second] = item.first;
    }

    // 去掉连接符号
    int prefix_len = 0;
    if (continuing_subword_prefix_.size() > 0) {
        prefix_len = continuing_subword_prefix_[0].size();
    }

    // 要求外部将merges传进来
    for (int i = 0; i < merges.size(); i++) {
        // 获取合并规则
        auto&& merge = merges[i];
        try {
            // 合并规则中内容必须要在词典中
            auto a_id = vocab_.at(merge.first);
            auto b_id = vocab_.at(merge.second);

            // 合并规则中内容必须要在词典中
            auto new_token = merge.first + merge.second.substr(prefix_len);
            auto new_id = vocab_.at(new_token);

            merges_[core::Pair(a_id, b_id)] = {i, new_id};
        } catch (...) {
            throw std::runtime_error("Can't merge token out of the vocabulary ");
        }
    }

    if (unk_token_.size() > 0) {
        try {
            // 添加 unk_token 到unk_token_id_ 中
            unk_token_id_.emplace_back(vocab_.at(unk_token_.front()));
        } catch (...) {
            std::ostringstream oss;
            oss << "Unk token " << unk_token_.front() << " not found in vocab";
            throw std::runtime_error(oss.str());
        }
    }
}

void BPE::tokenize_with_cache(const std::string& text, std::vector<core::Token>* tokens) {
    core::BPEWord bpe_word;
    // 判断文本是否在缓存中,如果改文本在合并规则中,那么直接获取拆分之后的词
    if (cache_.get_value(text, &bpe_word)) {
        // 将词转换为token
        word_to_tokens(bpe_word, tokens);
    } else {
        // 根据合并规则，将文本拆分成多个词
        merge_word(text, &bpe_word);
        // 将每个词转换为token
        word_to_tokens(bpe_word, tokens);
        // 将词加入缓存
        cache_.set_value(text, bpe_word);
    }
}

void BPE::word_to_tokens(const core::BPEWord& bpe_word, std::vector<core::Token>* tokens) {

}

void BPE::merge_word(const std::string& word1, core::BPEWord* bpe_word) {

}

std::vector<core::Token> BPE::tokenize(const std::string& text) {
    std::vector<core::Token> tokens;
    std::cout << "BPE tokenizer " << std::endl;
    std::cout << "text: " << text << std::endl;

    if (text.empty()) {
        return tokens;
    }

    if (dropout_.empty()) {
        return tokens;
    }


    return tokens;
}

void BPE::get_vocab_and_merges_from_file(const std::string& vocab_json_path,
                                const std::string& merge_path,
                                core::Vocab* vocab,
                                core::Merges* merges) {
    *vocab = BPE::get_vocab_from_file(vocab_json_path);
    *merges = BPE::get_merges_from_file(merge_path);
}

core::Vocab BPE::get_vocab_from_file(const std::string& vocab_json_path) {
    std::ifstream fin(vocab_json_path);
    core::Vocab vocab;
    nlohmann::json vocab_json;
    fin >> vocab_json;
    for (auto it = vocab_json.begin(); it != vocab_json.end(); ++it) {
        vocab[it.key()] = it.value();
    }

    VLOG(6) << "vocab size: " << vocab.size();
    return vocab;

}
core::Merges BPE::get_merges_from_file(const std::string& merge_path) {
    core::Merges merges;
    std::ifstream fin(merge_path);
    std::string word_str;
    while (std::getline(fin, word_str)) {
        // 句首，表示该merges.txt 由哪一个版本的tokenizer生成
        if (word_str.find("#version") == 0) {
            continue;
        }

        std::pair<std::string, std::string> result;
        construct_merges_pair(word_str, &result);
        merges.emplace_back(result);
    }

    return merges;
}

void BPE::construct_merges_pair(const std::string& word_line,
                                std::pair<std::string, std::string>* pair_result) {
    // 找到第一个词的开始和结束位置
    auto pair_a_begin = word_line.find_first_not_of(WHITESPACE); 
    auto pair_a_end = word_line.find_first_of(WHITESPACE, pair_a_begin); 

    // 找到第二个词的开始和结束位置
    auto pair_b_begin = word_line.find_first_not_of(WHITESPACE, pair_a_end);
    auto pair_b_end = word_line.find_first_of(WHITESPACE, pair_b_begin);
    *pair_result = {word_line.substr(pair_a_begin, pair_a_end - pair_a_begin),
               word_line.substr(pair_b_begin, pair_b_end - pair_b_begin)};

}

}  // namespace models
}  // namespace leomax_tokenizer
