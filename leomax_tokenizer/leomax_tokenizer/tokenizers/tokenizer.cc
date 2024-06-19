#include "tokenizer.h"
#include "../normalizers/bert_normalizer.h"
#include "../pretokenizers/bert_pretokenizer.h"
#include <iostream>
namespace leomax_tokenizer {
namespace tokenizers {
void Tokenizer::encode_single_text(const std::string& raw_text) {
    std::cout << "Tokenizer::encode_single_text, raw_text = " << raw_text << std::endl;
    this->encode_text_to_encoding(raw_text);
}

void Tokenizer::encode_text_to_encoding(const std::string& text) {
    std::cout << "Tokenizer::encode_text_to_encoding, text = " << text << std::endl;
    pretokenizers::PreTokenizedString pretokenized;
    // 调用词典，对原始的文本进行归一化
    this->added_vocabulary_.extract_and_normalize(this->normalizer_.get(),
                                                  text, 
                                                  &pretokenized);
    std::cout << "Tokenizer::encode_text_to_encoding, pretokenized = " 
                << pretokenized.get_original_str()
                << ", split size: " << pretokenized.get_split_size() << std::endl;
    this->do_tokenize(&pretokenized, text);
}

void Tokenizer::do_tokenize(pretokenizers::PreTokenizedString* pretokenized, 
                            const std::string& text) {
    std::cout << "Tokenizer::do_tokenize" << std::endl;
    // 使用预分词的分词器进行处理
    pretokenized->tokenize([&](normalizers::NormalizedString* normalized) {
        return this->get_model_ptr()->tokenize(normalized->get_str());
    });

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

template void Tokenizer::set_pretokenizer(const pretokenizers::BertPreTokenizer& pretokenizer);

}   // namespace tokenizers
}   // namespace leomax_tokenizer