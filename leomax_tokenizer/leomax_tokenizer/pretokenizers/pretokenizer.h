#ifndef LEOMAX_TOKENIZER_PRETOKENIZERS_PRETOKENIZER_H_
#define LEOMAX_TOKENIZER_PRETOKENIZERS_PRETOKENIZER_H_
#include <string>

namespace leomax_tokenizer {
namespace pretokenizers {

class PreTokenizedString {
public:
    PreTokenizedString() = default;

    PreTokenizedString(const std::string& original);

};

}       // namespace pretokenizers
}       // namespace leomax_tokenizer
#endif