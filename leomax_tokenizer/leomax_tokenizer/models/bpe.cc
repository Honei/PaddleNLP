//
// Created by xiongxinlei on 5/28/24.
//
#include "bpe.h"
#include <iostream>
namespace leomax_tokenizer {
namespace models {

BPE::BPE() :
    fuse_unk_(false){
}

BPE::BPE(const core::Vocab& vocab,
         const core::Merges& merges,
         const std::vector<float>& dropout,
         bool fuse_unk) :
        dropout_(dropout),
        fuse_unk_(fuse_unk) {

}

void BPE::tokenize_with_cache(const std::string& text, std::vector<core::Token>& tokens) {
    core::BPEWord bpe_word;
    if (cache_.get_value(text &bpe_worod)) {
        word_to_tokens(bpe_word, tokens);
    } else {
        // 根据合并规则，将文本拆分成多个词
        merge_word(text, &bpe_word);
        // 将每个词转换为token
        word_to_tokens(bpe_word, tokens);
        // 将词加入缓存
        cache_.set_value(text, bpe_word);
    }
}

std::vector<core::Token> BPE::tokenize(const std::string& text) {
    std::vector<core::Token> tokens;
    std::cout << "BPE tokenizer " << std::endl;
    std::cout << "text: " << text << std::endl;

    if (text.empty()) {
        return tokens;
    }

    if (dropout_.empty()) {
        return tokens;
    }


    return tokens;
}
}  // namespace models
}  // namespace leomax_tokenizer
