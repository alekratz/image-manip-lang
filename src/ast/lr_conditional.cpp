#include "ast/lr_conditional.hpp"
#include "visitor.hpp"

namespace ast {

void lr_conditional::children_accept(visitor* guest)
{
    accept(guest);
    if(left != nullptr) left->accept(guest);
    if(right != nullptr) right->accept(guest);
}

void lr_conditional::traverse_top_down(visitor* guest)
{
    accept(guest);
    if(left != nullptr) left->traverse_top_down(guest);
    if(right != nullptr) right->traverse_top_down(guest);
}

void lr_conditional::traverse_bottom_up(visitor* guest)
{
    if(left != nullptr) left->traverse_bottom_up(guest);
    if(right != nullptr) right->traverse_bottom_up(guest);
    accept(guest);
}

} /* namespace ast */