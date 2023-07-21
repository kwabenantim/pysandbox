#include "PyAbstractCellPopulation.hpp"

#include "Identifiable.hpp"
#include "Typecasters.hpp"

#include <pybind11/pybind11.h>

#include <boost/shared_ptr.hpp>

#include <string>

namespace py = pybind11;

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
std::string PyAbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>::ToString() const
{
  PYBIND11_OVERRIDE_PURE(std::string, AbstractCellPopulation_ELEMENT_SPACE, ToString, );
}

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
void bind_AbstractCellPopulation(py::module &m)
{
  const std::string name{"AbstractCellPopulation_" +
                         std::to_string(ELEMENT_DIM) + "_" +
                         std::to_string(SPACE_DIM)};

  py::class_<AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>,
             boost::shared_ptr<AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>>,
             PyAbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>,
             Identifiable>(m, name.c_str())
      .def(py::init<const std::vector<unsigned>>(),
           py::arg("indices"))
      .def("ToString", &AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>::ToString);
}

template class PyAbstractCellPopulation<2, 2>;
template class PyAbstractCellPopulation<3, 3>;

template void bind_AbstractCellPopulation<2, 2>(py::module &m);
template void bind_AbstractCellPopulation<3, 3>(py::module &m);
