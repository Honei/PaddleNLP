#include "pypretokenizers.h"
namespace py = pybind11;
namespace leomax_tokenizer {

namespace pybind {

void bind_pretokenizers(pybind11::module *m) {
    auto submodule = m->def_submodule("pretokenizers");

    py::class_<pretokenizers::PreTokenizer, PyPreTokenizer>(submodule, "PreTokenizer")
        .def(py::init<>())
        .def("__call__", &pretokenizers::PreTokenizer::operator());

    py::class_<pretokenizers::BertPreTokenizer, PyBertPreTokenizer>(submodule, "BertPreTokenizer")
        .def(py::init<>())
        .def("__call__", &pretokenizers::BertPreTokenizer::operator());
}

}
}