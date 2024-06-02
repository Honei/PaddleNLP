#ifndef LEOMAX_TOKENIZER_PRETOKENIZERS_PRETOKENIZER_H_
#define LEOMAX_TOKENIZER_PRETOKENIZERS_PRETOKENIZER_H_
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "../core/base.h"
#include "../normalizers/normalizer.h"

namespace leomax_tokenizer {
namespace pretokenizers {

/*****************************被分词的文本**********************************/
class StringSplit {
public:
    StringSplit() = default;
    StringSplit(normalizers::NormalizedString&& normalized) :
            normalized_(std::move(normalized)) {
        std::cout << "StringSplit(normalizers::NormalizedString&& normalized): "
                  << normalized_.get_original() << std::endl;
    }

public:
    normalizers::NormalizedString normalized_;
    std::vector<core::Token> tokens_;
};

class PreTokenizedString {
public:
    PreTokenizedString() = default;

    PreTokenizedString(const std::string& original);
    void set_original_str(const std::string& orignal);
    void split(std::function<void(int idx, 
                                  normalizers::NormalizedString*,
                                  std::vector<StringSplit>*)> split_fn);

private:
    std::string original_;
    std::vector<StringSplit> splits_;
};

}       // namespace pretokenizers
}       // namespace leomax_tokenizer
#endif