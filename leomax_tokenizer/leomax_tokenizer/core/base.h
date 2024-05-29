//
// Created by xiongxinlei on 5/28/24.
//
#include "unordered_map"
#include <utility>
#ifndef LEOMAX_TOKENIZER_BASE_H
#define LEOMAX_TOKENIZER_BASE_H
namespace leomax_tokenizer {
namespace core {

using Offset = std::pair<uint32_t, uint32_t>;
using Vocab = std::unordered_map<std::string, uint32_t>;
using VocabReversed = std::unordered_map<uint32_t, std::string>;
using Merges = std::vector<std::pair<std::string, std::string>>;
using Pair = std::pair<uint32_t, uint32_t>;
using MergeMap = std::map<Pair, std::pair<uint32_t, uint32_t>>;


struct Token {
  uint32_t id_;     // token id
  std::string value_;
  Offset offset_;
  Token(uint32_t id, const std::string& value, const Offset& offset) :
      id_(id), value_(value), offset_(offset) {
  }
};

struct Symbol {
    uint32_t ch_;  // 符号的id
    int prev_;
    int next_;
    size_t len_;
    Symbol() = default;
    Symbol(uint32_t ch, int prev, int next, size_t len):
    ch_(ch), prev_(prev), next_(next), len_(len) {

    }
};

struct BPEWord {
    BPEWord() = default;
    BPEWord(size_t capacity) {

    }

    std::vector<Symbol> symbols_;
};

}
}

#endif  // LEOMAX_TOKENIZER_BASE_H
