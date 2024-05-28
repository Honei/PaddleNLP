//
// Created by xiongxinlei on 5/28/24.
//
#include "bpe.h"
#include <iostream>
namespace leomax_tokenizer {
namespace models {

BPE::BPE() :
    fuse_unk_(false) {
}

BPE::BPE(const core::Vocab& vocab,
         const core::Merges& merges,
         const std::vector<float>& dropout,
         bool fuse_unk) :
        dropout_(dropout),
        fuse_unk_(fuse_unk) {
    init(merges);
}

void BPE::init(const core::Merges& merges) {
    if (dropout_.empty()) {
        return;
    }

    if (dropout_[0] > 1.0 || dropout_[0] < 0.0) {
        throw std::runtime_error("dropout probability must be in range [0,1]");
    }

    // 构建token id到token的映射关系
    for (auto& item: vocab_) {
        vocab_reversed_[item.second] = item.first;
    }

    int prefix_len = 0;
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
//            merges_.insert(core::Pair(a_id, b_id), {i, new_id});
        } catch (...) {
//            throw std::runtime_error("Can't merge token out of the vocabulary ");
        }
    }
}

void BPE::tokenize_with_cache(const std::string& text, std::vector<core::Token>* tokens) {
    core::BPEWord bpe_word;
    // 判断文本是否在缓存中,如果改文本在合并规则中,那么直接获取拆分之后的词
    if (cache_.get_value(text, &bpe_word)) {
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

void word_to_tokens(const core::BPEWord& bpe_word, std::vector<core::Token>* tokens) {

}

void merge_words(const std::string& word1, core::BPEWord* bpe_word) {

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
}  // namespace models
}  // namespace leomax_tokenizer
