#ifndef AST_FUNCALL_HPP
#define AST_FUNCALL_HPP

#include "args_list.hpp"
#include "expr.hpp"
#include <memory>

namespace ast {

class funcall;
typedef std::shared_ptr<funcall> funcall_p;

class funcall 
    : public expr
{
public:
    funcall(args_list_p args)
        : args(args) { }
    virtual ~funcall() = default;

public:
    args_list_p args;
};

} /* namespace ast */
#endif