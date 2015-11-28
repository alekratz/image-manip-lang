#ifndef AST_DIMENSION_HPP
#define AST_DIMENSION_HPP

#include "expr.hpp"
#include <cstdint>

namespace ast {

class dimension;
typedef std::shared_ptr<dimension> dimension_p;

/* This class is abstract */
class dimension 
    : public expr
{
public:
    dimension(int64_t first, int64_t second)
        : first(first)
        , second(second) { }
    virtual ~dimension() = default;

public:
    const int64_t first;
    const int64_t second;
};

} /* namespace ast */
#endif