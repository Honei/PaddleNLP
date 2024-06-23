#include "metaspace.h"

namespace leomax_tokenizer {
namespace pretokenizers {

MetaSpacePreTokenizer::MetaSpacePreTokenizer(const std::string& replacement,
                                            bool add_prefix_space) :
                replacement_(replacement), 
                add_prefix_space_(add_prefix_space) {
    
}
void MetaSpacePreTokenizer::operator()(PreTokenizedString* pretokenized) const {

}
}
}