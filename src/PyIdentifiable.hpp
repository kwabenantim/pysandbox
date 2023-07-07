#ifndef _PY_IDENTIFIABLE_HPP_
#define _PY_IDENTIFIABLE_HPP_

#include "Identifiable.hpp"

#include <pybind11/pybind11.h>

class PyIdentifiable : public Identifiable
{
public:
  // Inherit constructors
  using Identifiable::Identifiable;
};

void registerIdentifiable(pybind11::module &m);

#endif //_PY_IDENTIFIABLE_HPP_
