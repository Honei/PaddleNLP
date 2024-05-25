if (WITH_PYTHON)
    cc_library(core_tokenizers SHARED 
        SRCS pybind/pybind.cc tokenizers/ernie_fast_tokenizer.cc)
endif()