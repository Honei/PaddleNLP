from . import core_tokenizers as C

class Tokenizer:
    def __init__(self, model):
        self._tokenizer = None
        if model is not None:
            self._tokenizer = "调用C接口"