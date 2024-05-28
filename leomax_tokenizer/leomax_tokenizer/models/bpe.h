//
// Created by xiongxinlei on 5/28/24.
//

#ifndef LEOMAX_TOKENIZER_BPE_H
#define LEOMAX_TOKENIZER_BPE_H
#include "models.h"
#include "vector"
#include "../core/base.h"
#include "../core/cache.h"
namespace leomax_tokenizer {
namespace models {

class BPE : public Model {
public:
    BPE();
    BPE(const core::Vocab& vocab,
        const core::Merges& merges,
        const std::vector<float>& dropout = {},
        bool fuse_unk = false);

    virtual std::vector<core::Token> tokenize(const std::string& text) override;

private:
    void init(const core::Merges& merges);
    void tokenize_with_cache(const std::string& text, std::vector<core::Token>* tokens);
    void word_to_tokens(const core::BPEWord& bpe_word, std::vector<core::Token>* tokens);
    void merge_word(const std::string& word, core::BPEWord* bpe_word);
    void merge_words(const std::string& word1, core::BPEWord* bpe_word);
private:
    core::Vocab vocab_;
    core::VocabReversed vocab_reversed_;
//    core::MergeMap merges_;
    core::Cache<std::string, core::BPEWord> cache_;
    std::vector<float> dropout_;
    bool fuse_unk_;


};

} // namespace models
} // namespace leomax_tokenizer

#endif  // LEOMAX_TOKENIZER_BPE_H
