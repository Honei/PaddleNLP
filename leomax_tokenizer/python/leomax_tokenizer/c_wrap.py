from . import core_tokenizers as C
from .tokenizer_impl.data_tokenizer import InputSequence
class Tokenizer:
    def __init__(self, model):
        self._tokenizer = None
        if model is not None:
            self._tokenizer = C.Tokenizer(model._model)
            
    def encode(self, 
               text: InputSequence, 
               pair):
        return self._tokenizer.encode(text)