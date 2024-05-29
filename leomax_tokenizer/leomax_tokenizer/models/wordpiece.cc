//
// Created by xiongxinlei on 5/29/24.
//
#include "wordpiece.h"

namespace leomax_tokenizer {
namespace models {

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
    for (const auto& item : vocab) {
        vocab_reversed_[item.second] = item.first;
    }

    // 计算得到 unk 的id
    unk_token_id_ = vocab_.at(unk_token);
}

std::vector<core::Token> WordPiece::tokenize(const std::string &text) {
    std::vector<core::Token> tokens;
    std::cout << "WordPiece tokenize" << std::endl;
    return tokens;
}

}   // namespace models
}   // namespace leomax_tokenizer