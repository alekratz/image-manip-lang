#ifndef AST_EXPR_HPP
#define AST_EXPR_HPP

#include "tree.hpp"

namespace ast {

class expr;
typedef std::shared_ptr<expr> expr_p;

class expr 
    : public virtual tree
{
    /* dtor */
public:
    virtual ~expr() = 0;

    /* operations */
public:
    virtual void accept(visitor* guest) = 0;
};

} /* namespace ast */
#endif