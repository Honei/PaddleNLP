#ifndef LEOMAX_TOKENIZER_NORMALIZERS_NORMALIZER_H_
#define LEOMAX_TOKENIZER_NORMALIZERS_NORMALIZER_H_
#include <string>
#include <vector>
namespace leomax_tokenizer {
namespace normalizers {

/*****************************规整之后的字符串********************************/
class NormalizedString {
public:
    NormalizedString(const std::string& original);
    const std::string& get_str() const {
        return this->normalized_;
    }
    const std::string& get_original() const {
        return this->original_;
    }
private:
    std::string original_;      // 原始字符串
    std::string normalized_;    // 规整之后的字符串
    uint32_t original_shift_;   // 
};

struct Normalizer { 
    virtual void operator()(NormalizedString* mut_str) const = 0;
};

}       // namespace normalizers
}       // namespace leomax_tokenizer
#endif