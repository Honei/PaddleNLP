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
using Merges = std::vector<std::pair<std::string, std::string>>;


struct Token {
  uint32_t id_;     // token id
  std::string value_;
  Offset offset_;
  Token(uint32_t id, const std::string& value, const Offset& offset) :
      id_(id), value_(value), offset_(offset) {
  }
};

}
}

#endif  // LEOMAX_TOKENIZER_BASE_H
