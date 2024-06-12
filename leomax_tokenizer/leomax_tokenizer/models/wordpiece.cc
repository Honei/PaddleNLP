//
// Created by xiongxinlei on 5/29/24.
//

#include <fstream>
#include "wordpiece.h"

namespace leomax_tokenizer {
namespace models {

const std::string WHITESPACE = " \n\r\t\f\v";

WordPiece::WordPiece() :
    unk_token_("[UNK]"),
    continuing_subword_prefix_("##"),
    max_input_chars_per_word_(100),
    unk_token_id_(0),
    handle_chinese_chars_(true) {

}

WordPiece::WordPiece(const core::Vocab &vocab,
          const std::string& unk_token,
          size_t max_input_chars_per_word,
          const std::string& continuing_subword_prefix,
          bool handle_chinese_chars) :
       vocab_(vocab),
       unk_token_(unk_token),
       max_input_chars_per_word_(max_input_chars_per_word),
       continuing_subword_prefix_(continuing_subword_prefix),
       handle_chinese_chars_(handle_chinese_chars) {
    std::cout << "WordPiece constructor" << std::endl;
    for (const auto& item : vocab) {
        vocab_reversed_[item.second] = item.first;
    }

    // 计算得到 unk 的id，可能找不到，没有抛出异常
    // NOTE: todo: 考虑抛出异常，如果没有 unk_token，则抛出异常
    unk_token_id_ = vocab_.at(unk_token);
}

std::vector<core::Token> WordPiece::tokenize(const std::string &text) {
    std::vector<core::Token> tokens;
    std::cout << "WordPiece tokenize" << std::endl;
    return tokens;
}

core::Vocab WordPiece::get_vocab_from_file(const std::string &vocab_file) {
    std::cout << "WordPiece get_vocab_from_file, file name: " << vocab_file << std::endl;
    std::ifstream fin(vocab_file);
    core::Vocab vocab;
    if (!fin.is_open()) {
        std::cerr << "Can't open file: " << vocab_file << std::endl;
        return vocab;
    }

    constexpr int MAX_BUFFER_SIZE = 256;
    char word[MAX_BUFFER_SIZE];
    int idx = 0;
    while (fin.getline(word, MAX_BUFFER_SIZE)) {
        std::string word_str = word;
        // 去到句首的空格内容
        auto leading_spaces = word_str.find_first_not_of(WHITESPACE);
        if (std::string::npos != leading_spaces) {
            leading_spaces = std::min(leading_spaces, word_str.length() - 1);
            word_str = word_str.substr(leading_spaces); // 去掉句首空格
        }

        auto trailing_spaces = word_str.find_last_not_of(WHITESPACE);
        if (std::string::npos != trailing_spaces) {
            word_str = word_str.substr(0, trailing_spaces + 1); // 去掉句尾空格
        }

        // NOTE: TODO: 如果word_str之前存在过，则直接跳过
        if (!word_str.empty()) {
            vocab[word_str] = idx++;
        }
    }

    fin.close();
    std::cout << "WordPiece get_vocab_from_file done" << std::endl;
    return vocab;
}

WordPiece WordPiece::get_wordpiece_from_file( 
                    const std::string& vocab_file,
                    const std::string& unk_token,
                    size_t max_input_chars_per_word,
                    const std::string& continuing_subword_prefix) {
    std::cout << "WordPiece get_wordpiece_from_file" << std::endl;
    auto vocab = get_vocab_from_file(vocab_file);
    return WordPiece(vocab, 
                     unk_token, 
                     max_input_chars_per_word, 
                     continuing_subword_prefix);
}

bool WordPiece::token_to_id(const std::string& token, uint32_t *id) const {
    return true;
}

size_t WordPiece::get_vocab_size() const {
    return vocab_.size();
}

}   // namespace models
}   // namespace leomax_tokenizer