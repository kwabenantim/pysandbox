#include "PyConcreteCellPopulation.hpp"

#include "Typecasters.hpp"

#include <pybind11/pybind11.h>

#include <boost/shared_ptr.hpp>

#include <string>

namespace py = pybind11;

template <unsigned DIM>
std::string PyConcreteCellPopulation<DIM>::ToString() const
{
  PYBIND11_OVERRIDE(std::string, ConcreteCellPopulation_DIM, ToString, );
}

template <unsigned DIM>
void registerConcreteCellPopulation(py::module &m)
{
  const std::string name{"ConcreteCellPopulation_" + std::to_string(DIM)};

  py::class_<ConcreteCellPopulation<DIM>,
             boost::shared_ptr<ConcreteCellPopulation<DIM>>,
             AbstractCellPopulation<DIM, DIM>>(m, name.c_str())
      .def(py::init<const std::vector<unsigned>>(),
           py::arg("indices"))
      .def("ToString", &ConcreteCellPopulation<DIM>::ToString);
}

template class PyConcreteCellPopulation<2>;
template class PyConcreteCellPopulation<3>;

template void registerConcreteCellPopulation<2>(py::module &m);
template void registerConcreteCellPopulation<3>(py::module &m);
