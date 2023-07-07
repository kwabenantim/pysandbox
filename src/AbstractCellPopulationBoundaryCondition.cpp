#include "AbstractCellPopulationBoundaryCondition.hpp"

#include "AbstractCellPopulation.hpp"

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::AbstractCellPopulationBoundaryCondition(
    AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM> *pCellPopulation)
{
  _pCellPopulation = pCellPopulation;
}

template class AbstractCellPopulationBoundaryCondition<2, 2>;
template class AbstractCellPopulationBoundaryCondition<3, 3>;