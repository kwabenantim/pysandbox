#include "ConcreteCellPopulation.hpp"

#include <string>

template <unsigned DIM>
std::string ConcreteCellPopulation<DIM>::ToString() const
{
  return "ConcreteCellPopulation_" + std::to_string(DIM);
}

template class ConcreteCellPopulation<2>;
template class ConcreteCellPopulation<3>;
