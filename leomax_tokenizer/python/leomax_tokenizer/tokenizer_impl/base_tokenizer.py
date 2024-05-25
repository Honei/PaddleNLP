__ALL__ = ['BaseFastTokenizer']

class BaseFastTokenizer:
    def __init__(self, tokenizer_impl, param_dict):
        self._tokenize = tokenizer_impl
        self._param_dict = param_dict