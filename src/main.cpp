#include "PyAbstractCellPopulation.hpp"
#include "PyAbstractCellPopulationBoundaryCondition.hpp"
#include "PyConcreteCellPopulation.hpp"
#include "PyConcreteCellPopulationBoundaryCondition.hpp"
#include "PyIdentifiable.hpp"

#include <pybind11/pybind11.h>

PYBIND11_MODULE(pysandbox, m)
{
  bind_Identifiable(m);
  bind_AbstractCellPopulation<2, 2>(m);
  bind_AbstractCellPopulation<3, 3>(m);
  bind_AbstractCellPopulationBoundaryCondition<2, 2>(m);
  bind_AbstractCellPopulationBoundaryCondition<3, 3>(m);
  bind_ConcreteCellPopulation<2>(m);
  bind_ConcreteCellPopulation<3>(m);
  bind_ConcreteCellPopulationBoundaryCondition<2, 2>(m);
  bind_ConcreteCellPopulationBoundaryCondition<3, 3>(m);
}
