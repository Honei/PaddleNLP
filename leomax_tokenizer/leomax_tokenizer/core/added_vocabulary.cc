#include <iostream>
#include "added_vocabulary.h"
#include "../pretokenizers/pretokenizer.h"
namespace leomax_tokenizer {
namespace core {
AddedVocabulary::AddedVocabulary() :
    split_trie_({std::make_shared<re2::RE2>(""), Vocab()}),
    split_normalized_trie_({std::make_shared<re2::RE2>(""), Vocab()}) {
    
}

void AddedVocabulary::extract_and_normalize(const normalizers::Normalizer* normalizers,
                                            const std::string& text,
                                            pretokenizers::PreTokenizedString* pretokenized) {
    std::cout << "AddedVocabulary::extract_and_normalize" << std::endl;
    pretokenized->set_original_str(text);
    pretokenized->split([&](int idx,
                            normalizers::NormalizedString* normalized,
                            std::vector<pretokenizers::StringSplit>* string_splits) {
                    this->split_with_indices(*normalized, this->split_trie_, string_splits);         
                });
}

bool AddedVocabulary::find_match(const std::string& text,
                                const MatchSet& pattern, 
                                std::vector<MatchResult>* match_results) {
    std::cout << "AddedVocabulary::find_match" << std::endl;
    std::cout << "text: " << text << std::endl;
    if (text.empty()) {
        return false;
    }

    std::vector<MatchResult> splits;
    size_t start = 0;
    size_t start_offset = 0;
    size_t end = text.length();
    re2::StringPiece result_str;
    std::cout << "start = " << start 
              << ", end = " << end 
              << ", text = " << text 
            //   << ", pattern = " << pattern.first->pattern() 
              << std::endl;
    return true;
}

bool AddedVocabulary::split_with_indices(const normalizers::NormalizedString& normalized,
                                        const MatchSet& pattern,
                                        std::vector<pretokenizers::StringSplit>* split_results) {
    std::vector<MatchResult> match_results;
    bool status = find_match(normalized.get_str(), pattern, &match_results);
    return true;
}

}
}