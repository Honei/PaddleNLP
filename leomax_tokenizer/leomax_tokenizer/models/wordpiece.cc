//
// Created by xiongxinlei on 5/29/24.
//
#include "wordpiece.h"

namespace leomax_tokenizer {
namespace models {

WordPiece::WordPiece() {

}

WordPiece::WordPiece(const core::Vocab &vocab,
          const std::string& unk_token,
          size_t max_input_chars_per_word,
          const std::string& continuing_subword_prefix,
          bool handle_chinese_chars) {

}

std::vector<core::Token> WordPiece::tokenize(const std::string &text) {
    std::vector<core::Token> tokens;
    std::cout << "WordPiece tokenize" << std::endl;
    return tokens;
}

}   // namespace models
}   // namespace leomax_tokenizer