#ifndef AST_EXPR_HPP
#define AST_EXPR_HPP

#include "args_list.hpp"
#include "tree.hpp"

namespace ast {

class expr;
typedef std::shared_ptr<expr> expr_p;

/* This class is abstract */
class expr 
    : public tree
{
public:
    virtual ~expr() = 0;
};

} /* namespace ast */
#endif