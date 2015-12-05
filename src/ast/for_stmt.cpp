#include "ast.hpp"
#include "visitor.hpp"

namespace ast {
void for_stmt::children_accept(visitor* guest)
{
    accept(guest);
    if(range != nullptr) range->accept(guest);
    if(lines != nullptr) lines->accept(guest);
}

void for_stmt::traverse_top_down(visitor* guest)
{
    accept(guest);
    if(range != nullptr) range->traverse_top_down(guest);
    if(lines != nullptr) lines->traverse_top_down(guest);
}
void for_stmt::traverse_bottom_up(visitor* guest)
{
    if(range != nullptr) range->traverse_bottom_up(guest);
    if(lines != nullptr) lines->traverse_bottom_up(guest);
    accept(guest);
}

} /* namespace ast */