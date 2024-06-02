//
// Created by xiongxinlei on 5/27/24.
//

#include "pymodels.h"
#include "pytokens.h"
namespace py = pybind11;
namespace leomax_tokenizer {
namespace pybind {

void bind_models(pybind11::module* m) {
    auto submodule = m->def_submodule("models", "The models module");
    py::class_<models::Model, PyModel/*辅助类*/>(submodule, "Model")
        .def(py::init<>())
        .def("tokenize", &models::Model::tokenize);

    py::class_<models::BPE, PyBPE/*辅助类*/>(submodule, "BPE")
        .def(py::init<>())
        .def("tokenize", &models::BPE::tokenize);

    py::class_<models::WordPiece, PyWordPiece/*辅助类*/>(submodule, "WordPiece")
        .def(py::init<>())
        .def(py::init<const core::Vocab&,
                      const std::string&, 
                      size_t,
                      const std::string&,
                      bool>(),
            py::arg("vocab"),
            py::arg("unk_token") = "[UNK]",
            py::arg("max_input_chars_per_word") = 100,
            py::arg("continuing_subword_prefix") = "##",
            py::arg("handle_chinese_chars") = true) 
        .def("tokenize", &models::WordPiece::tokenize)
        .def_static("from_file",
                    &models::WordPiece::get_wordpiece_from_file, 
                    py::arg("vocab"), 
                    py::arg("unk_token") = "[UNK]",
                    py::arg("max_input_chars_per_word") = 100,
                    py::arg("continuing_subword_prefix") = "##")
        .def_static("read_file", 
                    &models::WordPiece::get_vocab_from_file, 
                    py::arg("vocab"));
}

} //pybind
} // leomax_tokenizer