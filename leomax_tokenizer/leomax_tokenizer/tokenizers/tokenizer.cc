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
    this->do_tokenize(&pretokenized, text);
}

void Tokenizer::do_tokenize(pretokenizers::PreTokenizedString* pretokenized, 
                            const std::string& text) {
    std::cout << "Tokenizer::do_tokenize" << std::endl;

}

}   // namespace tokenizers
}   // namespace leomax_tokenizer