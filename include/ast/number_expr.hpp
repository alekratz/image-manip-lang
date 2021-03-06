#ifndef AST_NUMBER_EXPR_HPP
#define AST_NUMBER_EXPR_HPP

#include "expr.hpp"
#include <cstdint>

namespace ast {

class number_expr;
typedef std::shared_ptr<number_expr> number_expr_p;

class number_expr 
    : public expr
{
public:
    number_expr(int64_t value)
        : value(value) { }
    virtual ~number_expr() = default;

public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest) { accept(guest); }
    virtual void traverse_top_down(visitor* guest) { accept(guest); }
    virtual void traverse_bottom_up(visitor* guest) { accept(guest); }

public:
    const int64_t value;
};

} /* namespace ast */
#endif