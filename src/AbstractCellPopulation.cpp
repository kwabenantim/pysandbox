#include "AbstractCellPopulation.hpp"

#include <vector>

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>::AbstractCellPopulation(const std::vector<unsigned> indices)
{
  _size = indices.size();
}

template class AbstractCellPopulation<2>;
template class AbstractCellPopulation<3>;
