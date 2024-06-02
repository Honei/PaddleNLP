#include "pytokenizers.h"
#include "../models/wordpiece.h"

namespace py = pybind11;    // 简化pybind11的命名空间

namespace leomax_tokenizer {
namespace pybind {

void bind_tokenizers(pybind11::module* m) {
    // auto submodule = m->def_submodule("tokenizers", "The tokenizers module");
    py::class_<tokenizers::Tokenizer>(*m, "Tokenizer")
        .def(py::init<>(), "Create WordPiece tokenizer")
        .def(py::init<const models::WordPiece&>(), "Create WordPiece tokenizer")
        .def("encode", 
             &tokenizers::Tokenizer::encode_single_text,
             py::arg("text"));

}
}   // namespace pybind
}   // namespace leomax_tokenizer