#include "PyAbstractCellPopulationBoundaryCondition.hpp"

#include "Identifiable.hpp"
#include "Typecasters.hpp"

#include <pybind11/pybind11.h>

#include <boost/shared_ptr.hpp>

#include <string>

namespace py = pybind11;

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
std::string PyAbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::ToString() const
{
  PYBIND11_OVERRIDE_PURE(std::string, AbstractCellPopulationBoundaryCondition_ELEMENT_SPACE, ToString, );
}

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
void bind_AbstractCellPopulationBoundaryCondition(py::module &m)
{
  const std::string name{"AbstractCellPopulationBoundaryCondition_" +
                         std::to_string(ELEMENT_DIM) + "_" +
                         std::to_string(SPACE_DIM)};

  py::class_<AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>,
             boost::shared_ptr<AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>>,
             PyAbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>,
             Identifiable>(m, name.c_str())
      .def(py::init<AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM> *>(),
           py::arg("pCellPopulation"))
      .def("ToString", &AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::ToString);
}

template class PyAbstractCellPopulationBoundaryCondition<2, 2>;
template class PyAbstractCellPopulationBoundaryCondition<3, 3>;

template void bind_AbstractCellPopulationBoundaryCondition<2, 2>(py::module &m);
template void bind_AbstractCellPopulationBoundaryCondition<3, 3>(py::module &m);
