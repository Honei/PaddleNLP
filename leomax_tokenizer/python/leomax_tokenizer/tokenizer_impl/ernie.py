#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Copyright (c) 2024 PaddlePaddle Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
from ..models import WordPiece, FastWordPiece
class ErnieFastTokenizer:
    def __init__(self,
                 vocab=None,
                 unk_token="[UNK]",
                 sep_token="[SEP]",
                 cls_token="[CLS]",
                 pad_token="[PAD]",
                 mask_token="[MASK]",
                 clean_text=True,
                 handle_chinese_chars=True,
                 strip_accents=True,
                 lowercase=True,
                 wordpieces_prefix="##",
                 max_sequence_len=None,
                 max_input_chars_per_word=100,
                 use_fast_wordpiece=False,
                 use_fast_wordpiece_with_pretokenization=False):
        # tokenizer_model = FastWordPiece if use_fast_wordpiece else WordPiece
        pass