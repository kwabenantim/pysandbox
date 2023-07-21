#ifndef _PY_CONCRETE_CELL_POPULATION_HPP_
#define _PY_CONCRETE_CELL_POPULATION_HPP_

#include "ConcreteCellPopulation.hpp"

#include <pybind11/pybind11.h>

#include <string>

template <unsigned DIM>
class PyConcreteCellPopulation : public ConcreteCellPopulation<DIM>
{
public:
  // Alias for macros
  typedef ConcreteCellPopulation<DIM> ConcreteCellPopulation_DIM;

  // Inherit constructors
  using ConcreteCellPopulation<DIM>::ConcreteCellPopulation;

  // Trampolines for virtual functions
  std::string ToString() const override;
};

template <unsigned DIM>
void bind_ConcreteCellPopulation(pybind11::module &m);

#endif //_PY_CONCRETE_CELL_POPULATION_HPP_
