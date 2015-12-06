#include "ast/qualified_id.hpp"
#include "visitor.hpp"

namespace ast {

void qualified_id::children_accept(visitor* guest)
{
    accept(guest);
}

void qualified_id::traverse_top_down(visitor* guest)
{
    accept(guest);
}

void qualified_id::traverse_bottom_up(visitor* guest)
{
    accept(guest);
}

} /* namespace ast */