#ifndef AST_NUMBER_EXPR_HPP
#define AST_NUMBER_EXPR_HPP

#include "expr.hpp"
#include <cstdint>

namespace ast {

class number_expr;
typedef std::shared_ptr<number_expr> number_expr_p;

/* This class is abstract */
class number_expr 
    : public expr
{
public:
    number_expr(int64_t value)
        : value(value) { }
    virtual ~number_expr() = default;

public:
    virtual void accept(visitor* guest);

public:
    const int64_t value;
};

} /* namespace ast */
#endif