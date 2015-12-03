#ifndef AST_RANGE_HPP
#define AST_RANGE_HPP

#include "expr.hpp"
#include <cstdint>

namespace ast {

class range;
typedef std::shared_ptr<range> range_p;

/* This class is abstract */
class range 
    : public expr
{
public:
    range(int64_t start, int64_t end)
        : start(start)
        , end(end) { }
    virtual ~range() = default;

public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest)
        { accept(guest); }

public:
    const int64_t start;
    const int64_t end;
};

} /* namespace ast */
#endif