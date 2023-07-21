#include "PyConcreteCellPopulationBoundaryCondition.hpp"

#include "Typecasters.hpp"

#include <pybind11/pybind11.h>

#include <boost/shared_ptr.hpp>

#include <string>

namespace py = pybind11;

using boost::numeric::ublas::c_vector;

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
std::string PyConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::ToString() const
{
  PYBIND11_OVERRIDE(std::string, ConcreteCellPopulationBoundaryCondition_ELEMENT_SPACE, ToString, );
}

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
void bind_ConcreteCellPopulationBoundaryCondition(py::module &m)
{
  const std::string name{"ConcreteCellPopulationBoundaryCondition_" +
                         std::to_string(ELEMENT_DIM) + "_" +
                         std::to_string(SPACE_DIM)};

  py::class_<ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>,
             boost::shared_ptr<ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>>,
             PyConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>,
             AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>>(m, name.c_str())
      .def(py::init<AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM> *,
                    c_vector<double, SPACE_DIM>,
                    c_vector<double, SPACE_DIM>>(),
           py::arg("pCellPopulation"),
           py::arg("point"),
           py::arg("normal"))
      .def("ToString", &ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::ToString);
}

template class PyConcreteCellPopulationBoundaryCondition<2, 2>;
template class PyConcreteCellPopulationBoundaryCondition<3, 3>;

template void bind_ConcreteCellPopulationBoundaryCondition<2, 2>(py::module &m);
template void bind_ConcreteCellPopulationBoundaryCondition<3, 3>(py::module &m);
