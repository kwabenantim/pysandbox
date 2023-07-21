#include "PyIdentifiable.hpp"

#include "Typecasters.hpp"

#include <pybind11/pybind11.h>

#include <boost/shared_ptr.hpp>

namespace py = pybind11;

void bind_Identifiable(py::module &m)
{
  py::class_<Identifiable,
             boost::shared_ptr<Identifiable>,
             PyIdentifiable>(m, "Identifiable")
      .def("GetIdentifier", &Identifiable::GetIdentifier);
}
