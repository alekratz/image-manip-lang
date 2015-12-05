#include "ast/funcall_conditional.hpp"
#include "visitor.hpp"

namespace ast {

void funcall_conditional::children_accept(visitor* guest)
{
    accept(guest);
    if(funcall != nullptr) funcall->accept(guest);
}

void funcall_conditional::traverse_top_down(visitor* guest)
{
    accept(guest);
    if(funcall != nullptr) funcall->traverse_top_down(guest);
}

void funcall_conditional::traverse_bottom_up(visitor* guest)
{
    accept(guest);
    if(funcall != nullptr) funcall->traverse_bottom_up(guest);
}

} /* namespace ast */