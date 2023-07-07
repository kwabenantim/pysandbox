#ifndef _ABSTRACT_CELL_POPULATION_BOUNDARY_CONDITION_HPP_
#define _ABSTRACT_CELL_POPULATION_BOUNDARY_CONDITION_HPP_

#include "AbstractCellPopulation.hpp"
#include "Identifiable.hpp"

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
class AbstractCellPopulationBoundaryCondition : public Identifiable
{
protected:
  AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM> *_pCellPopulation;

public:
  AbstractCellPopulationBoundaryCondition() = delete;
  AbstractCellPopulationBoundaryCondition(AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM> *pCellPopulation);

  virtual ~AbstractCellPopulationBoundaryCondition() = default;

  virtual std::string ToString() const = 0;
};

#endif //_ABSTRACT_CELL_POPULATION_BOUNDARY_CONDITION_HPP_