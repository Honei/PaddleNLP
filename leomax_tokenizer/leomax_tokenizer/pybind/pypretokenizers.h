#ifndef LEOMAX_TOKENIZER_PYPRETOKENIZERS_H_
#define LEOMAX_TOKENIZER_PYPRETOKENIZERS_H_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../pretokenizers/pretokenizer.h"
#include "../pretokenizers/bert_pretokenizer.h"
namespace leomax_tokenizer {
namespace pybind {

class PyPreTokenizer : public pretokenizers::PreTokenizer {
public:
    using pretokenizers::PreTokenizer::PreTokenizer;
    virtual void operator() (
        pretokenizers::PreTokenizedString * pretokenized) const override {
            PYBIND11_OVERLOAD_PURE_NAME (
                void,
                pretokenizers::PreTokenizer,
                "__call__",
                operator(),
                pretokenized
            );
        }
};

class PyBertPreTokenizer : public pretokenizers::BertPreTokenizer {
public:
    using pretokenizers::BertPreTokenizer::BertPreTokenizer;
    virtual void operator() (
        pretokenizers::PreTokenizedString * pretokenized) const override {
            PYBIND11_OVERLOAD_NAME (
                void,
                pretokenizers::BertPreTokenizer,
                "__call__",
                operator(),
                pretokenized
            );
    }

};

void bind_pretokenizers(pybind11::module *m);
}
}

#endif