#include <iostream>
#include "normalizer.h"
#include <codecvt>
#include <locale>
#include "../utils/utf8.h"
namespace leomax_tokenizer {
namespace normalizers {
NormalizedString::NormalizedString(const std::string& original) :
                original_(original),
                normalized_(original),
                original_shift_(0) { 
    std::cout << "==================== Normalized String Constructor ===============" << std::endl;
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
    std::u32string u32normalized = conv.from_bytes(normalized_);
    std::cout << "u32normalized: " << u32normalized.length() << std::endl;
    for (int i = 0; i < u32normalized.length(); ++i) {
        auto new_normalized_char_len = utils::get_utf8_char_len(u32normalized[i]);
        uint32_t start = 0;
        uint32_t end = 0;
        if (i != 0) {
            start = alignments_.back().second;
        }
        end = start + new_normalized_char_len;
        std::cout << "u32 normalized start: " << start << ", end: " << end << std::endl;
        for (int j = 0; j < new_normalized_char_len; ++j) {
            alignments_.push_back({start, end});
        }
    }

    std::cout << "alignments: " << alignments_.size() << std::endl;
    for (auto itr = alignments_.begin(); itr != alignments_.end(); ++itr){
        std::cout << "alignments: " << itr->first << ", " << itr->second << std::endl;
    }
    
}
NormalizedString::NormalizedString(NormalizedString&& other):
    original_(std::move(other.original_)),
    normalized_(std::move(other.normalized_)),
    alignments_(std::move(other.alignments_)),
    original_shift_(other.original_shift_) {

}

NormalizedString&  NormalizedString::operator=(NormalizedString&& other) {
    original_ = std::move(other.original_);
    normalized_ = std::move(other.normalized_);
    alignments_ = std::move(other.alignments_);
    original_shift_ = other.original_shift_;
    return *this;
}

bool NormalizedString::slice(core::Range range, NormalizedString* normalized, bool origin_range) const {
    std::cout << "normalized string slice " << std::endl;
    core::Range normalized_range = range;
    core::Range original_range = range;
    std::cout << "slice origin range: " << origin_range << std::endl;
    if (origin_range){ 
        convert_offsets(&normalized_range, true);
    } else {
        convert_offsets(&original_range, false);
    }

    uint32_t n_shift = original_range.first;
    original_range.first =
        (std::min)(original_range.first,
                   static_cast<uint32_t>(this->original_.length() - 1));
    normalized->original_ = this->original_.substr(
                    original_range.first, original_range.second - original_range.first);
    normalized_range.first =
        (std::min)(normalized_range.first,
                   static_cast<uint32_t>(this->normalized_.length() - 1));

    normalized->normalized_ = this->normalized_.substr(
                                    normalized_range.first,
                                    normalized_range.second - normalized_range.first);
    normalized->alignments_.reserve(normalized_range.second -
                                    normalized_range.first);
    for (uint32_t i = normalized_range.first; i < normalized_range.second;
         ++i) {
        normalized->alignments_.emplace_back(
                        this->alignments_[i].first - n_shift,
                        this->alignments_[i].second - n_shift);
    }
    normalized->original_shift_ = this->original_shift_ + original_range.first;
    return true;

}

bool NormalizedString::convert_offsets(core::Range* range, 
                                       bool origin_range) const {
    std::cout << "convert offsets" << std::endl;
    auto len_original = get_original_len();
    auto len_normalized = get_len();
    std::cout << "len original: " << len_original << std::endl;
    std::cout << "len normalized: " << len_normalized << std::endl;
    std::cout << "range: [ " << range->first << ", " << range->second << " ]" << std::endl;
    if (range->first == range->second) {
        return true;
    }

    if (range->first > range->second) {
        return false;
    }

    if (origin_range && original_.empty() && 
        (range->first == 0 && range->second == 0)) {
        range->second = len_normalized;
        return true;
    }

    if (!origin_range && normalized_.empty() && 
        (range->first == 0 && range->second == 0)) {
        range->second = len_original;
        return true;
    }

    if (origin_range) {
        int start = -1;
        int end = -1;
        for (int i = 0; i < alignments_.size(); ++i) {
            if (range->second >= alignments_[i].second) {
                if (start < 0 && range->first <= alignments_[i].first) {
                    if (alignments_[i].first != alignments_[i].second) {
                        start = i;
                    }
                }
                if (range->second >= alignments_[i].second) {
                    end = i + 1;
                }
            }
        }
        if (start > 0 && end < 0) {
            *range = {start, start};
        } else if (start < 0 && end > 0) {
            *range = {end, end};
        } else if (start > 0 && end > 0) {
            *range = {start, end};
        } else {
            return false;
        }
    } else {
        std::cout << "convert offsets alignments size: " << alignments_.size() << std::endl;
        range->first = alignments_[range->first].first;
        range->second = alignments_[range->second - 1].second; // [start, end)
    }

    std::cout << "convert offsets finished" << std::endl;
    return true;
}

}
}