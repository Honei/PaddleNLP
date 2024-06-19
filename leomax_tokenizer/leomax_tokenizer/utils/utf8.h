#ifndef LEOMAX_TOKENIZER_UTILS_UTF8_H_
#define LEOMAX_TOKENIZER_UTILS_UTF8_H_
#include <string>
#include <cstdint>
namespace leomax_tokenizer {
namespace utils {


inline uint32_t unicode_to_utf8(uint32_t unchr) {
    uint32_t utf8 = 0;
    if (unchr < 0x00000080) {
        utf8 = unchr;
    } else if (unchr < 0x00000800) {
        utf8 = (unchr << 2) & 0x1F00;
        utf8 |= (unchr & 0x3F);
        utf8 |= 0x0000C080;
    } else if (unchr < 0x00010000) {
        utf8 = (unchr << 4) & 0x0F0000;   // upper 4 bits
        utf8 |= (unchr << 2) & 0x003F00;  // next 6 bits
        utf8 |= (unchr & 0x3F);           // last 6 bits
        utf8 |= 0x00E08080;
    } else if (unchr < 0x00110000) {      // 3-byte unicode
        utf8 = (unchr << 6) & 0x07000000;   // upper 3 bits
        utf8 |= (unchr << 4) & 0x003F0000;  // next 6 bits
        utf8 |= (unchr << 2) & 0x00003F00;  // next 6 bits
        utf8 |= (unchr & 0x3F);             // last 6 bits
        utf8 |= static_cast<uint32_t>(0xF0808080);
    }
    return utf8;
}

inline uint32_t bytes_in_unicode_char(uint32_t chr) {
    uint32_t count = 1;
    // no if-statements means no divergence
    count += static_cast<int>((chr & static_cast<uint32_t>(0x0000FF00)) > 0);
    count += static_cast<int>((chr & static_cast<uint32_t>(0x00FF0000)) > 0);
    count += static_cast<int>((chr & static_cast<uint32_t>(0xFF000000)) > 0);
    return count;
}
inline uint32_t get_utf8_char_len(uint32_t u32chr) {
    return bytes_in_unicode_char(unicode_to_utf8(u32chr));
}

}
}
#endif