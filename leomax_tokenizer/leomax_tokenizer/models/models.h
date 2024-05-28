//
// Created by xiongxinlei on 5/27/24.
//

#ifndef MODELS_MODELS_H
#define MODELS_MODELS_H
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace leomax_tokenizer {
namespace models {
class Model {
public:
  virtual void tokenize(const std::string& tokens) = 0;
};

}
}
#endif  // MODELS_MODELS_H
