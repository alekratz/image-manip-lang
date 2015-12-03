#ifndef AST_TREE_HPP
#define AST_TREE_HPP

#include "visitor_adaptor.hpp"
#include "types.hpp"
#include <memory>

namespace ast {

class tree
    : public visitor_adaptor
{
public:
    tree() = default;
    virtual ~tree() = 0;
};

typedef std::shared_ptr<tree> tree_p;

} /* namespace ast */

#endif