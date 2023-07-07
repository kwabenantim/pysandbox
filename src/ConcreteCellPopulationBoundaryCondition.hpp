#ifndef _CONCRETE_CELL_POPULATION_BOUNDARY_CONDITION_HPP_
#define _CONCRETE_CELL_POPULATION_BOUNDARY_CONDITION_HPP_

#include "AbstractCellPopulationBoundaryCondition.hpp"
#include "AbstractCellPopulation.hpp"

#include <boost/numeric/ublas/vector.hpp>

#include <string>

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM = ELEMENT_DIM>
class ConcreteCellPopulationBoundaryCondition : public AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>
{
protected:
  boost::numeric::ublas::c_vector<double, SPACE_DIM> _point;
  boost::numeric::ublas::c_vector<double, SPACE_DIM> _normal;

public:
  ConcreteCellPopulationBoundaryCondition(
      AbstractCellPopulation<SPACE_DIM> *population,
      boost::numeric::ublas::c_vector<double, SPACE_DIM> point,
      boost::numeric::ublas::c_vector<double, SPACE_DIM> normal);

  std::string ToString() const override;
};

#endif //_CONCRETE_CELL_POPULATION_BOUNDARY_CONDITION_HPP_