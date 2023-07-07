#ifndef _IDENTIFIABLE_HPP_
#define _IDENTIFIABLE_HPP_

#include <string>

class Identifiable
{
public:
    Identifiable() = default;
    virtual ~Identifiable() = default;

    std::string GetIdentifier() const;
};

#endif // _IDENTIFIABLE_HPP_
