#include "normalizer.h"

namespace leomax_tokenizer {
namespace normalizers {
NormalizedString::NormalizedString(const std::string& original) :
                original_(original),
                normalized_(original),
                original_shift_(0) {        

}

}
}