#include "AbstractCellPopulation.hpp"
#include "AbstractCellPopulationBoundaryCondition.hpp"
#include "ConcreteCellPopulation.hpp"
#include "ConcreteCellPopulationBoundaryCondition.hpp"
#include "Identifiable.hpp"
#include "PyAbstractCellPopulation.hpp"
#include "PyAbstractCellPopulationBoundaryCondition.hpp"
#include "PyConcreteCellPopulation.hpp"
#include "PyConcreteCellPopulationBoundaryCondition.hpp"
#include "PyIdentifiable.hpp"

#include <pybind11/pybind11.h>

PYBIND11_MODULE(pysandbox, m)
{
  registerIdentifiable(m);
  registerAbstractCellPopulation<2, 2>(m);
  registerAbstractCellPopulation<3, 3>(m);
  registerAbstractCellPopulationBoundaryCondition<2, 2>(m);
  registerAbstractCellPopulationBoundaryCondition<3, 3>(m);
  registerConcreteCellPopulation<2>(m);
  registerConcreteCellPopulation<3>(m);
  registerConcreteCellPopulationBoundaryCondition<2, 2>(m);
  registerConcreteCellPopulationBoundaryCondition<3, 3>(m);
}
