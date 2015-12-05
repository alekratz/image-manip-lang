#ifndef AST_FOR_STMT_HPP
#define AST_FOR_STMT_HPP

#include "tree.hpp"
#include "line.hpp"
#include "expr.hpp"

namespace ast {

class for_stmt;
typedef std::shared_ptr<for_stmt> for_stmt_p;

class for_stmt 
    : public line
{
    /* ctor/dtor */
public:
    for_stmt(cstref varname, expr_p range, line_list_p lines)
        : varname(varname)
        , range(range)
        , lines(lines) { }
    virtual ~for_stmt() = default;

    /* operations */
public:
    virtual void operator()()
        { }
    virtual void children_accept(visitor* guest);
    virtual void accept(visitor* guest);

    /* members */
public:
    std::string varname;
    expr_p range;
    line_list_p lines;
};

} /* namespace ast */
#endif