#!/usr/bin/env python3
# from leomax_tokenizer.tokenizer_impl import SentencePieceBPELeoMaxTokenizer
import leomax_tokenizer
from leomax_tokenizer import WordPiece
from leomax_tokenizer import ErnieFastTokenizer

class TestModel(leomax_tokenizer.core_tokenizers.models.Model):
    def __init__(self):
        super().__init__()

    def tokenize(self, tokens):
        print("测试模型")
        return tokens
if __name__ == '__main__':
    # tokenizer = SentencePieceBPELeoMaxTokenizer(vocab='vocab.json',
    #                                             merges='merges.txt',)
    print(leomax_tokenizer.core_tokenizers.add(1, 2))
    model = TestModel()
    print(model.tokenize("今天天气很不错"))

    model = leomax_tokenizer.core_tokenizers.models.BPE()
    print(model.tokenize("今天天气很不错"))

    model = leomax_tokenizer.core_tokenizers.models.WordPiece()
    print(model.tokenize("今天天气很不错"))
    
    # print(WordPiece.__dict__)
    vocab = WordPiece.read_file("vocab.txt")
    fast_tokenizer = ErnieFastTokenizer(vocab=vocab)
    output = fast_tokenizer.encode("我爱中国")
    print(output)
