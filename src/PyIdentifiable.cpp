#include "PyIdentifiable.hpp"

#include "Typecasters.hpp"

#include <pybind11/pybind11.h>

namespace py = pybind11;

void registerIdentifiable(py::module &m)
{
  py::class_<Identifiable,
             boost::shared_ptr<Identifiable>,
             PyIdentifiable>(m, "Identifiable")
      .def("GetIdentifier", &Identifiable::GetIdentifier);
}
