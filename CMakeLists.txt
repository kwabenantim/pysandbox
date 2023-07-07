# Minimum CMake version on Ubuntu 20.04 LTS
cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

# Project
project(pysandbox VERSION 0.0.1 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Pybind11 headers
add_subdirectory(extern/pybind11)

# Set up Pybind11 module
pybind11_add_module(pysandbox MODULE 
  src/main.cpp
  src/AbstractCellPopulation.cpp
  src/AbstractCellPopulation.hpp
  src/AbstractCellPopulationBoundaryCondition.cpp
  src/AbstractCellPopulationBoundaryCondition.hpp
  src/ConcreteCellPopulation.cpp
  src/ConcreteCellPopulation.hpp
  src/ConcreteCellPopulationBoundaryCondition.cpp
  src/ConcreteCellPopulationBoundaryCondition.hpp
  src/Identifiable.cpp
  src/Identifiable.hpp
  src/PyAbstractCellPopulation.cpp
  src/PyAbstractCellPopulation.hpp
  src/PyAbstractCellPopulationBoundaryCondition.cpp
  src/PyAbstractCellPopulationBoundaryCondition.hpp
  src/PyConcreteCellPopulation.cpp
  src/PyConcreteCellPopulation.hpp
  src/PyConcreteCellPopulationBoundaryCondition.cpp
  src/PyConcreteCellPopulationBoundaryCondition.hpp
  src/PyIdentifiable.cpp
  src/PyIdentifiable.hpp
)

# Find Boost
find_package(Boost REQUIRED ALL)
if(Boost_FOUND)
  target_include_directories(pysandbox SYSTEM PRIVATE ${Boost_INCLUDE_DIR})
endif()

# Add install target for scikit-build
install(TARGETS pysandbox DESTINATION .)
