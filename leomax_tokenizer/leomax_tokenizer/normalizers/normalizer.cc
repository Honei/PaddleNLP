#include "normalizer.h"

namespace leomax_tokenizer {
namespace normalizers {
NormalizedString::NormalizedString(const std::string& original) :
                original_(original),
                normalized_(original),
                original_shift_(0) {        

}
NormalizedString::NormalizedString(NormalizedString&& other):
    original_(std::move(other.original_)),
    normalized_(std::move(other.normalized_)),
    original_shift_(other.original_shift_) {

}

NormalizedString&  NormalizedString::operator=(NormalizedString&& other) {
    original_ = std::move(other.original_);
    normalized_ = std::move(other.normalized_);
    original_shift_ = other.original_shift_;
    return *this;
}

}
}