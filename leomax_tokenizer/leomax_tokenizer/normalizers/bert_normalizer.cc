#include "bert_normalizer.h"
#include "../utils/unicode_utils.h"
#include <cstdint>

namespace leomax_tokenizer {
namespace normalizers {

BertNormalizer::BertNormalizer(bool clean_text,
                             bool handle_chinese_chars,
                             bool strip_accents,
                             bool lowercase) :
    clean_text_(clean_text),
    handle_chinese_chars_(handle_chinese_chars),
    strip_accents_(strip_accents),
    lowercase_(lowercase) {

}    

void BertNormalizer::operator() (NormalizedString *input) const {
    if (this->clean_text_) {
        do_clean_text(input);
    }
}

void BertNormalizer::do_clean_text(NormalizedString *input) const {
    (*input).filter_char([](char32_t ch) -> bool {
        return !(ch == 0 || ch == 0xffd || unicode::is_control(ch));
    });
}

}
}