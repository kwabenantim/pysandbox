#ifndef _PY_CONCRETE_CELL_POPULATION_BOUNDARY_CONDITION_HPP_
#define _PY_CONCRETE_CELL_POPULATION_BOUNDARY_CONDITION_HPP_

#include "ConcreteCellPopulationBoundaryCondition.hpp"

#include <pybind11/pybind11.h>

#include <string>

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
class PyConcreteCellPopulationBoundaryCondition : public ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>
{
public:
  // Alias for macros
  typedef ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM> ConcreteCellPopulationBoundaryCondition_ELEMENT_SPACE;

  // Inherit constructors
  using ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::ConcreteCellPopulationBoundaryCondition;

  // Trampolines for virtual functions
  std::string ToString() const override;
};

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
void bind_ConcreteCellPopulationBoundaryCondition(pybind11::module &m);

#endif //_PY_CONCRETE_CELL_POPULATION_BOUNDARY_CONDITION_HPP_
