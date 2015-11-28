#ifndef AST_FUNCALL_HPP
#define AST_FUNCALL_HPP

#include "args_list.hpp"
#include "tree.hpp"
#include <memory>

namespace ast {

class funcall 
    : public tree
{
public:
    funcall(args_list_p args)
        : args(args) { }
    virtual ~funcall() = default;

public:
    args_list_p args;
};

typedef std::shared_ptr<funcall> funcall_p;

} /* namespace ast */
#endif