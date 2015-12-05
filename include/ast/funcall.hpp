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
    /* ctor/dtor */
public:
    funcall(cstref name, args_list_p args)
        : name(name)
        , args(args) { }
    virtual ~funcall() = default;

public:
    /* operations */
public:
    virtual void children_accept(visitor* guest);
    virtual void accept(visitor* guest);
    virtual void traverse_top_down(visitor* guest);
    virtual void traverse_bottom_up(visitor* guest);
    
    virtual void operator()() {}

    /* members */
public:
    std::string name;
    args_list_p args;
};

} /* namespace ast */
#endif