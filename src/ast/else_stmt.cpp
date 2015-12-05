#include "ast/else_stmt.hpp"
#include "visitor.hpp"

namespace ast {

void else_stmt::children_accept(visitor* guest)
{
    accept(guest);
    if(lines != nullptr) lines->accept(guest);
}

void else_stmt::traverse_top_down(visitor* guest)
{
    accept(guest);
    if(lines != nullptr) lines->traverse_top_down(guest);
}

void else_stmt::traverse_bottom_up(visitor* guest)
{
    if(lines != nullptr) lines->traverse_bottom_up(guest);
    accept(guest);
}

} /* namespace ast */