from leomax_tokenizer.tokenizer_impl import SentencePieceBPELeoMaxTokenizer
import leomax_tokenizer
if __name__ == '__main__':
    # tokenizer = SentencePieceBPELeoMaxTokenizer(vocab='vocab.json',
    #                                             merges='merges.txt',)
    print(leomax_tokenizer.core_tokenizers.add(1, 2))