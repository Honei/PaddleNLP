from leomax_tokenizer.tokenizer_impl import SentencePieceBPELeoMaxTokenizer
if __name__ == '__main__':
    tokenizer = SentencePieceBPELeoMaxTokenizer(vocab='vocab.json',
                                                merges='merges.txt',)