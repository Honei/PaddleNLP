//
// Created by xiongxinlei on 5/28/24.
//

#ifndef LEOMAX_TOKENIZER_BPE_H
#define LEOMAX_TOKENIZER_BPE_H
#include "models.h"
#include "vector"
#include "../core/base.h"
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
    void tokenize_with_cache(const std::string& text, std::vector<core::Token>& tokens);
private:
    std::vector<float> dropout_;
    bool fuse_unk_;


};

} // namespace models
} // namespace leomax_tokenizer

#endif  // LEOMAX_TOKENIZER_BPE_H
