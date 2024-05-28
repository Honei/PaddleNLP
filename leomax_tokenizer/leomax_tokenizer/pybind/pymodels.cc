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
}

} //pybind
} // leomax_tokenizer