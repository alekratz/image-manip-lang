#ifndef AST_ARGS_LIST_HPP
#define AST_ARGS_LIST_HPP

#include "tree.hpp"
#include "tree_list.hpp"
#include <memory>

namespace ast {

class args_list 
    : public tree
    , public tree_list
{ };

typedef std::shared_ptr<args_list> args_list_p;

} /* namespace ast */
#endif