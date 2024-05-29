//
// Created by xiongxinlei on 5/29/24.
//

#ifndef LEOMAX_TOKENIZER_WORDPIECE_H
#define LEOMAX_TOKENIZER_WORDPIECE_H
#include "models.h"
#include "../core/base.h"

namespace leomax_tokenizer {
namespace models {
class WordPiece : public Model {
public:
    WordPiece();
    WordPiece(const core::Vocab &vocab,
              const std::string& unk_token = "[UNK]",
              size_t max_input_chars_per_word = 100,
              const std::string& continuing_subword_prefix = "##",
              bool handle_chinese_chars = true);
    std::vector<core::Token> tokenize(const std::string &text) override;
};

}  // namespace models
}  // namespace leomax_tokenizer
#endif  // LEOMAX_TOKENIZER_WORDPIECE_H
