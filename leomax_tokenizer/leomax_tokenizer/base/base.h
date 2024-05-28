//
// Created by xiongxinlei on 5/28/24.
//

#ifndef LEOMAX_TOKENIZER_BASE_H
#define LEOMAX_TOKENIZER_BASE_H

using Offset = std::pair<uint32_t, uint32_t>;

struct Token {
    uint32_t id_;     // token id
    std::string value_;
    Offset offset_;
    Token(uint32_t id, const std::string& value, const Offset& offset)
        id_(id), value_(value), offset_(offset): {
    }
};
#endif  // LEOMAX_TOKENIZER_BASE_H
