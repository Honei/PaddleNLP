from typing import List
from .. import core_tokenizers as C
from .wordpiece import WordPiece
from .base_model import Model
from .wordpiece import WordPiece

class BPE(Model):
    def __init__(self,
               vocab=None,
               merges=None,
               dropout=None,
               unk_token=None,
               fuse_unk=None):
        pass

class FastWordPiece(Model):
    def __init__(self,
                 vocab,
                 unk_token: str="[UNK]",
                 max_input_chars_per_word: int=100,
                 continuing_subword_prefix: str="##",
                 with_pretokenization: bool=False):
        self._model = None
        if vocab is not None:
            self._model = None
            # self._model = C.models.FastWordPiece
