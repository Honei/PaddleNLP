#include "tokenizer.h"
#include <iostream>
namespace leomax_tokenizer {
namespace tokenizers {
void Tokenizer::encode_single_text(const std::string& text) {
    std::cout << "Tokenizer::encode" << std::endl;
    this->encode_text_to_encoding(text);
}

void Tokenizer::encode_text_to_encoding(const std::string& text) {
    std::cout << "Tokenizer::encode_text_to_encoding" << std::endl;
    pretokenizers::PreTokenizedString pretokenized;
    this->added_vocabulary_.extract_and_normalize(this->normalizer_.get(),
                                                  text, &pretokenized);
    this->do_tokenize(&pretokenized, text);
}

void Tokenizer::do_tokenize(pretokenizers::PreTokenizedString* pretokenized, 
                            const std::string& text) {
    std::cout << "Tokenizer::do_tokenize" << std::endl;

}

bool Tokenizer::token_to_id(const std::string& token,
                           uint32_t *id) const {
    // 判断该token是否在词典中
    // 传入的是 model 的对象，不是指针
    return this->added_vocabulary_.token_to_id(token,
                                              *this->model_,
                                              id);
}

size_t Tokenizer::add_special_tokens(const std::vector<core::AddedToken>& tokens) {
    return this->added_vocabulary_.add_special_tokens(tokens, *this->model_);
}

}   // namespace tokenizers
}   // namespace leomax_tokenizer