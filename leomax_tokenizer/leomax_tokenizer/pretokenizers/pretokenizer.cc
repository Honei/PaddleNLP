#include "pretokenizer.h"


namespace leomax_tokenizer {
namespace pretokenizers {

PreTokenizedString::PreTokenizedString(const std::string& original) 
    : original_(original) {
    this->splits_.emplace_back(std::move(StringSplit(original_)));
}

PreTokenizedString::PreTokenizedString(
        const normalizers::NormalizedString& normalized) :
    original_(normalized.get_original_str()) {

}


PreTokenizedString& PreTokenizedString::operator=(PreTokenizedString&& other) {
  original_ = std::move(other.original_);
  splits_ = std::move(other.splits_);
  return *this;
}

void PreTokenizedString::set_original_str(const std::string& orignal) {
    
    this->original_ = orignal;
    this->splits_.clear();
    // 调用右值引用构造方法，重新构建 splits_
    this->splits_.emplace_back(this->original_);

    std::cout << "set original str to:" << this->original_ 
              << ", the splits size is:" << this->splits_.size() 
              << std::endl << std::endl;
}

StringSplit PreTokenizedString::get_split(int idx) {
    return this->splits_[idx];
}

void PreTokenizedString::split(std::function<void(int idx, 
                                                  normalizers::NormalizedString*,
                                                  std::vector<StringSplit>*)> split_fn) {
    // 遍历 splits_，如果 tokens 的数据 > 0，那么将该token保存到新的split中
    // todo: split_ 怎么获取？？
    std::vector<StringSplit> new_splits;        // 存储新的分词结果
    new_splits.reserve(this->splits_.size());

    for (int i = 0; i < this->splits_.size(); ++i) {
        // 如果 tokens 的数据 > 0，那么将该token保存到新的split中，不会重复分词
        if (this->splits_[i].tokens_.size() > 0) {     
            new_splits.push_back(std::move(this->splits_[i]));
            continue;
        }

        // 否则，调用 split_fn 进行分词
        split_fn(i, &this->splits_[i].normalized_, &new_splits);
    }

    this->splits_ = std::move(new_splits);
}

void PreTokenizedString::tokenize(
        std::function<std::vector<core::Token>(normalizers::NormalizedString*)>
         tokenize_fn) {
    std::cout << "pre tokenized string tokenizing..." << std::endl;
    std::cout << "this original str is:" << this->original_ 
             << ", the split size is:" << this->splits_.size() << std::endl;
    for (auto& split : this->splits_) {
        // 调用外部的分词器进行分词
        if (split.tokens_.empty()) {
            split.tokens_ = std::move(tokenize_fn(&split.normalized_));
        }
    }
}

std::vector<std::tuple<std::string, core::Offset, std::vector<core::Token>>> 
       PreTokenizedString::get_splits(bool is_original, const core::OffsetType& offset_type) const {
    std::vector<std::tuple<std::string, core::Offset, std::vector<core::Token>>>
      result;

    return result;
}


}       // namespace pretokenizers

}       // namepsace leomax_tokenizer