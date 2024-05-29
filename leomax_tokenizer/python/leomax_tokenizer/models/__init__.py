from abc import ABC

from typing import List
from .. import core_tokenizers as C
class Model(ABC):
    def tokenizer(self, tokens: List[str]):
        return self._model.tokenizer(tokens)


class BPE(Model):
    def __init__(self,
               vocab=None,
               merges=None,
               dropout=None,
               unk_token=None,
               fuse_unk=None):
        pass


class WordPiece(Model):
    def __init__(self,
                 vocab,
                 unk_token,
                 max_input_chars_per_word: int=100,
                 continuing_subword_prefix: str="##",
                 handle_chinese_chars: bool=True):
        self._model = None
        if vocab is not None:
            self._model = C.models.WordPiece(vocab,
                                             unk_token,
                                             max_input_chars_per_word,
                                             continuing_subword_prefix,
                                             handle_chinese_chars,
                                             handle_chinese_chars)
