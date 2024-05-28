from leomax_tokenizer.tokenizer_impl import SentencePieceBPELeoMaxTokenizer
import leomax_tokenizer
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
