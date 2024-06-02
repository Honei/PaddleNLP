__ALL__ = ['BaseFastTokenizer']

class BaseFastTokenizer:
    def __init__(self, tokenizer_impl, param_dict):
        self._tokenizer = tokenizer_impl
        self._param_dict = param_dict
        
    def encode(self, 
               text,
               pair=None):
        if text is None:
            raise ValueError('encode: `text` cannot be None.')

        return self._tokenizer.encode(text, pair)