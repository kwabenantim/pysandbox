#include "Identifiable.hpp"

#include <typeinfo>

std::string Identifiable::GetIdentifier() const
{
  std::string id{typeid(this).name()};
  return id;
}
