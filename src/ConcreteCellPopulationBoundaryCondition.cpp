#include "ConcreteCellPopulationBoundaryCondition.hpp"

#include "AbstractCellPopulation.hpp"

#include <boost/numeric/ublas/vector.hpp>

#include <string>

using boost::numeric::ublas::c_vector;

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::ConcreteCellPopulationBoundaryCondition(
    AbstractCellPopulation<SPACE_DIM> *population,
    c_vector<double, SPACE_DIM> point,
    c_vector<double, SPACE_DIM> normal)
    : AbstractCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>(population),
      _point(point),
      _normal(normal)
{
}

template <unsigned ELEMENT_DIM, unsigned SPACE_DIM>
std::string ConcreteCellPopulationBoundaryCondition<ELEMENT_DIM, SPACE_DIM>::ToString() const
{
  return "ConcreteCellPopulationBoundaryCondition_" + std::to_string(ELEMENT_DIM) + "_" + std::to_string(SPACE_DIM);
}

template class ConcreteCellPopulationBoundaryCondition<2, 2>;
template class ConcreteCellPopulationBoundaryCondition<3, 3>;