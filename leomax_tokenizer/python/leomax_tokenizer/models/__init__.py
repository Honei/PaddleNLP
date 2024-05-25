from abc import ABC

from typing import List

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