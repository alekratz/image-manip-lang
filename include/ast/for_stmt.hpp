#ifndef AST_FOR_STMT_HPP
#define AST_FOR_STMT_HPP

#include "exec.hpp"
#include "expr.hpp"

namespace ast {

class for_stmt;
typedef std::shared_ptr<for_stmt> for_stmt_p;

/* This class is abstract */
class for_stmt 
    : public exec
{
public:
    for_stmt(cstref varname, expr_p range, );
    virtual ~for_stmt() = default;

public:
    std::string varname;
    expr_p range;
};

} /* namespace ast */
#endif