#ifndef AST_STRING_EXPR_HPP
#define AST_STRING_EXPR_HPP

#include "expr.hpp"
#include <string>
#include <iostream>

namespace ast {

class string_expr;
typedef std::shared_ptr<string_expr> string_expr_p;

/* This class is abstract */
class string_expr 
    : public expr
{
public:
    string_expr(cstref value)
        : value(value) { }
    virtual ~string_expr() = default;

public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest) { accept(guest); }
    virtual void traverse_top_down(visitor* guest) { accept(guest); }
    virtual void traverse_bottom_up(visitor* guest) { accept(guest); }

public:
    std::string value;
};

} /* namespace ast */
#endif