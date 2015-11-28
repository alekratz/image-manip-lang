#ifndef AST_TREE_HPP
#define AST_TREE_HPP

#include <memory>

namespace ast {

class tree
{
public:
    tree() = default;
    virtual ~tree() = default;

};

typedef std::shared_ptr<tree> tree_p;

} /* namespace ast */
#endif