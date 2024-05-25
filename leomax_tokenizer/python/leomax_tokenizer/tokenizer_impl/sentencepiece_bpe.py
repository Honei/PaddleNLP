from .base_tokenizer import BaseFastTokenizer
from ..c_wrap import Tokenizer
from ..models import BPE
__all__ = ["SentencePieceBPELeoMaxTokenizer"]

class SentencePieceBPELeoMaxTokenizer(BaseFastTokenizer):
    def __init__(self,
                 vocab=None,
                 merges=None,
                 unk_token="<unk>",
                 dropout=None,
                 fuse_unk=False) -> None:
        if vocab is not None and merges is not None:
            model = BPE(vocab=vocab, merges=merges,
                        dropout=dropout, unk_token=unk_token, fuse_unk=fuse_unk)
            tokenizer = Tokenizer(model)


