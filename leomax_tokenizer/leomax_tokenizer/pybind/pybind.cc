#include <pybind11/pybind11.h>
#include <Python.h>
namespace leomax_tokenizer {
namespace pybind {

namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}
PYBIND11_MODULE(core_tokenizers, m) {
    m.doc() = "pybind11 example plugin";
    m.def("add", &add, "A function which adds two number");
}

} // namespace pybind
} // namespace leomax_tokenizer


