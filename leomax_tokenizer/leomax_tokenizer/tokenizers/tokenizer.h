#ifndef LEOMAX_TOKENIZERS_TOKENIZER_H_
#define LEOMAX_TOKENIZERS_TOKENIZER_H_

#include <memory>
#include <iostream>
#include "../models/models.h"
#include "../core/added_vocabulary.h"
#include "../pretokenizers/pretokenizer.h"
#include "../normalizers/normalizer.h"
namespace leomax_tokenizer {
namespace tokenizers {
class Tokenizer {
public:
    Tokenizer():
        model_(nullptr) {
    }

    template<typename ModelType>
    Tokenizer(const ModelType& model) :
      model_(std::make_shared<ModelType>(model) /*实例化一个特定类型的分词模型*/),
      normalizer_(nullptr) {
        std::cout << "Tokenizer(const ModelType& model)" << std::endl;
    }
    bool token_to_id(const std::string& token,
                     uint32_t *id) const;
    size_t add_special_tokens(const std::vector<core::AddedToken>& tokens);
    void encode_single_text(const std::string& raw_text);

private: 
    void encode_text_to_encoding(const std::string& text);
    void do_tokenize(pretokenizers::PreTokenizedString* pretokenized, const std::string& text);
private:
    std::shared_ptr<models::Model> model_;
    std::shared_ptr<normalizers::Normalizer> normalizer_;
    core::AddedVocabulary added_vocabulary_;
};
}   // namespace tokenizers
}   // namespace leomax_tokenizer

#endif