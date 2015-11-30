#ifndef AST_TREE_HPP
#define AST_TREE_HPP

#include "types.hpp"
#include <memory>

class visitor;

namespace ast {

class tree
{
public:
    tree() = default;
    virtual ~tree() = 0;
public:
    void accept(visitor& guest);
};

typedef std::shared_ptr<tree> tree_p;

} /* namespace ast */

#endif