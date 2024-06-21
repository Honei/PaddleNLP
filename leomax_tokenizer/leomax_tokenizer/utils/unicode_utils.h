#ifndef LEOMAX_TOKENIZER_UTILS_UNICODE_UTILS_H_
#define LEOMAX_TOKENIZER_UTILS_UNICODE_UTILS_H_

#include "unicode/uchar.h"
#include "unicode/unistr.h"
namespace leomax_tokenizer {
namespace unicode {

inline bool is_control(int ch) {
    if (ch == '\t' || ch == '\n' || ch == '\r') {
        return false;// 这里是false???
    }

    return !u_isprint(ch);
}

}
}

#endif