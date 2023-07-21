#ifndef _PY_ABSTRACT_CELL_POPULATION_BOUNDARY_CONDITION_HPP_
#define _PY_ABSTRACT_CELL_POPULATION_BOUNDARY_CONDITION_HPP_

#include "AbstractCellPopulationBoundaryCondition.hpp"

#include <pybind11/pybind11.h>

#include <string>

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
class PyAbstractCellPopulationBoundaryCondition : public AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>
{
public:
  // Alias for macros
  typedef AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM> AbstractCellPopulationBoundaryCondition_ELEMENT_SPACE;

  // Inherit constructors
  using AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::AbstractCellPopulationBoundaryCondition;

  // Trampolines for virtual functions
  std::string ToString() const override;
};

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
void bind_AbstractCellPopulationBoundaryCondition(pybind11::module &m);

#endif //_PY_ABSTRACT_CELL_POPULATION_BOUNDARY_CONDITION_HPP_
