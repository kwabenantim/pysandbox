#ifndef _ABSTRACT_CELL_POPULATION_HPP_
#define _ABSTRACT_CELL_POPULATION_HPP_

#include "Identifiable.hpp"

#include <string>
#include <vector>

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
class AbstractCellPopulation : public Identifiable
{
protected:
  unsigned _size;

public:
  AbstractCellPopulation() = delete;
  AbstractCellPopulation(const std::vector<unsigned> indices);

  virtual ~AbstractCellPopulation() = default;

  virtual std::string ToString() const = 0;
};

#endif //_ABSTRACT_CELL_POPULATION_HPP_
