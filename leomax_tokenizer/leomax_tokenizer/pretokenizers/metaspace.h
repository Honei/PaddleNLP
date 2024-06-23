#ifndef LEOMAX_TOKENIZER_PRETOKENIZERS_METASPACE_H_
#define LEOMAX_TOKENIZER_PRETOKENIZERS_METASPACE_H_
#include "pretokenizer.h"

namespace leomax_tokenizer {
namespace pretokenizers {

class MetaSpacePreTokenizer : public PreTokenizer {
public: 
    MetaSpacePreTokenizer(const std::string& replacement = "\xe2\x96\x81",
                          bool add_prefix_space=true);
    virtual void operator()(PreTokenizedString* pretokenized) const override;

private:
    std::string replacement_;
    bool add_prefix_space_;
};

}
}

#endif