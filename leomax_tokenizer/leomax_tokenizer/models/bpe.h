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
        size_t cache_capacity = core::DEFAULT_CACHE_CAPACITY,
        const std::vector<float>& dropout = {},
        const std::vector<std::string>& unk_token = {},
        const std::vector<std::string>& continuing_subword_prefix = {},
        const std::vector<std::string>& end_of_word_suffix = {},
        bool fuse_unk = false);

    virtual std::vector<core::Token> tokenize(const std::string& text) override;

private:
    void init(const core::Merges& merges);
    void tokenize_with_cache(const std::string& text, std::vector<core::Token>* tokens);
    void word_to_tokens(const core::BPEWord& bpe_word, std::vector<core::Token>* tokens);
    void merge_word(const std::string& word, core::BPEWord* bpe_word);
private:
    core::Vocab vocab_;
    core::VocabReversed vocab_reversed_;
    core::MergeMap merges_;
    core::Cache<std::string, core::BPEWord> cache_;
    std::vector<float> dropout_;
    std::vector<std::string> unk_token_;
    std::vector<uint32_t> unk_token_id_;
    std::vector<std::string> continuing_subword_prefix_;
    std::vector<std::string> end_of_word_suffix_;
    bool fuse_unk_;

};

} // namespace models
} // namespace leomax_tokenizer

#endif  // LEOMAX_TOKENIZER_BPE_H
