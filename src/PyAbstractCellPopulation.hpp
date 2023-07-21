#ifndef _PY_ABSTRACT_CELL_POPULATION_HPP_
#define _PY_ABSTRACT_CELL_POPULATION_HPP_

#include "AbstractCellPopulation.hpp"

#include <pybind11/pybind11.h>

#include <string>

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
class PyAbstractCellPopulation : public AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>
{
public:
  // Alias for macros
  typedef AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM> AbstractCellPopulation_ELEMENT_SPACE;
  
  // Inherit constructors
  using AbstractCellPopulation<ELEMENT_DIM, SPACE_DIM>::AbstractCellPopulation;

  // Trampolines for virtual functions
  std::string ToString() const override;
};

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
void bind_AbstractCellPopulation(pybind11::module &m);

#endif //_PY_ABSTRACT_CELL_POPULATION_HPP_
