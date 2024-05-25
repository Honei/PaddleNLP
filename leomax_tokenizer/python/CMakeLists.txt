# 将 python 的 tokenizer 目录拷贝到二进制目录

message(STATUS "source directory: ${CMAKE_SOURCE_DIR}/python")
message(status "target directory: ${CMAKE_BINARY_DIR}/python")
add_custom_target(copy_python_tokenizers ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/python ${CMAKE_BINARY_DIR}/python DEPENDS core_tokenizers)


# 拷贝主目录下的 setup.py
add_custom_target(copy_setup ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/setup.py ${CMAKE_BINARY_DIR}/setup.py)