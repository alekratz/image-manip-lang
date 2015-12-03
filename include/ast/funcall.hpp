#ifndef AST_FUNCALL_HPP
#define AST_FUNCALL_HPP

#include "tree_list.hpp"
#include "expr.hpp"
#include "line.hpp"

namespace ast {

class funcall;
typedef std::shared_ptr<funcall> funcall_p;

class funcall 
    : public expr
    , public line
{
public:
    funcall(cstref name, args_list_p args)
        : name(name)
        , args(args) { }
    virtual ~funcall() = default;

public:
    virtual void children_accept(visitor* guest)
    {
        accept(guest);
        if(args != nullptr) args->accept(guest);
    }

public:
    std::string name;
    args_list_p args;

    virtual void operator()() {}
};

} /* namespace ast */
#endif