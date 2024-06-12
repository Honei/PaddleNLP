#include "bert_normalizer.h"

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

}

}
}