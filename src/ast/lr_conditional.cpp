#include "ast/lr_conditional.hpp"
#include "visitor.hpp"

namespace ast {

void lr_conditional::children_accept(visitor* guest)
{
    accept(guest);
    if(left != nullptr) left->accept(guest);
    if(right != nullptr) right->accept(guest);
}

} /* namespace ast */