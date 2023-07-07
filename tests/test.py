import numpy as np

from pysandbox import (
    ConcreteCellPopulationBoundaryCondition_2_2,
    ConcreteCellPopulationBoundaryCondition_3_3,
    ConcreteCellPopulation_2,
    ConcreteCellPopulation_3,
)

indices = [0, 1, 2, 3, 4, 5]
pop2D = ConcreteCellPopulation_2(indices)
print(pop2D.ToString())
print(pop2D.GetIdentifier())

point2D = np.array([0.0, 0.0])
normal2D = np.array([0.1, 0.0])
bc2D = ConcreteCellPopulationBoundaryCondition_2_2(pop2D, point2D, normal2D)
print(bc2D.ToString())

pop3D = ConcreteCellPopulation_3(indices)
print(pop3D.ToString())

point3D = np.array([0.0, 0.0, 1.0])
normal3D = np.array([0.0, 1.0, 0.0])
bc3D = ConcreteCellPopulationBoundaryCondition_3_3(pop3D, point3D, normal3D)
print(bc3D.ToString())
