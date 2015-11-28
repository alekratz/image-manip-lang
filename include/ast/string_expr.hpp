#ifndef AST_STRING_EXPR_HPP
#define AST_STRING_EXPR_HPP

#include "expr.hpp"
#include <string>

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
    std::string value;
};

} /* namespace ast */
#endif