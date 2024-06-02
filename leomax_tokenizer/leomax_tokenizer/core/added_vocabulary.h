#ifndef ADDED_VOCABULARY_H_
#define ADDED_VOCABULARY_H_

#include <string>
#include <memory>
#include <utility>
#include "re2/re2.h"
#include "base.h"
#include "../pretokenizers/pretokenizer.h"
#include "../normalizers/normalizer.h"

namespace leomax_tokenizer {
namespace core {
using re2::RE2;
using MatchSet = std::pair<std::shared_ptr<re2::RE2>, Vocab>;
using MatchResult = std::tuple<uint32_t, bool/*UNK flag*/, core::Offset>;

class AddedVocabulary {
public:
    AddedVocabulary();

    void extract_and_normalize(const normalizers::Normalizer* normalizers,
                               const std::string& text,
                               pretokenizers::PreTokenizedString* pretokenized);
    bool split_with_indices(const normalizers::NormalizedString& normalized,
                            const MatchSet& pattern,
                            std::vector<pretokenizers::StringSplit>* split_results);
    bool find_match(const std::string& text,
                    const MatchSet& pattern, 
                    std::vector<MatchResult>* match_results);

private:
    MatchSet split_trie_;
    MatchSet split_normalized_trie_;
};

}       // namespace core
}       // namespace leomax_tokenizer

#endif