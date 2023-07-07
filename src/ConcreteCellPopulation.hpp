#ifndef _CONCRETE_CELL_POPULATION_HPP_
#define _CONCRETE_CELL_POPULATION_HPP_

#include "AbstractCellPopulation.hpp"

#include <string>
#include <vector>

template <unsigned DIM>
class ConcreteCellPopulation : public AbstractCellPopulation<DIM, DIM>
{
public:
  ConcreteCellPopulation(const std::vector<unsigned> indices) : AbstractCellPopulation<DIM, DIM>(indices) {}

  std::string ToString() const override;
};

#endif //_CONCRETE_CELL_POPULATION_HPP_
