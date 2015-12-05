#include "ast/qualified_id.hpp"
#include "visitor.hpp"

namespace ast {

void qualified_id::children_accept(visitor* guest)
{
    accept(guest);
    if(tail != nullptr) tail->accept(guest);
}

void qualified_id::traverse_top_down(visitor* guest)
{
    accept(guest);
    if(tail != nullptr) tail->traverse_top_down(guest);
}

void qualified_id::traverse_bottom_up(visitor* guest)
{
    if(tail != nullptr) tail->traverse_bottom_up(guest);
    accept(guest);
}

} /* namespace ast */