add_subdirectory(models)

if (WITH_PYTHON)
    cc_library(core_tokenizers SHARED 
        SRCS pybind/pybind.cc tokenizers/ernie_fast_tokenizer.cc
            pybind/pytoken.cc pybind/pymodels.cc models/bpe.cc models/wordpiece.cc
            DEPS pybind)

    # 设置编译出来的库没有 "lib"前缀
    set_target_properties(core_tokenizers PROPERTIES PREFIX "")
    set_target_properties(core_tokenizers PROPERTIES SUFFIX ".so")
endif()