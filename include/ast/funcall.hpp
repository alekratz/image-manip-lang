#ifndef AST_FUNCALL_HPP
#define AST_FUNCALL_HPP

#include "args_list.hpp"
#include "expr.hpp"

namespace ast {

class funcall;
typedef std::shared_ptr<funcall> funcall_p;

class funcall 
    : public expr
{
public:
    funcall(cstref name, args_list_p args)
        : name(name)
        , args(args) { }
    virtual ~funcall() = default;

public:
    std::string name;
    args_list_p args;
};

} /* namespace ast */
#endif