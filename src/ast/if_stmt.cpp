#include "ast.hpp"
#include "visitor.hpp"

namespace ast {

void if_stmt::children_accept(visitor* guest)
{
    accept(guest);
    if(conditional != nullptr) conditional->children_accept(guest);
    if(lines != nullptr) lines->children_accept(guest);
    if(else_stmt != nullptr) lines->children_accept(guest);
}

void if_stmt::traverse_top_down(visitor* guest)
{
    accept(guest);
    if(conditional != nullptr) conditional->children_accept(guest);
    if(lines != nullptr) lines->children_accept(guest);
    if(else_stmt != nullptr) else_stmt->children_accept(guest);
}

void if_stmt::traverse_bottom_up(visitor* guest)
{
    if(conditional != nullptr) conditional->children_accept(guest);
    if(lines != nullptr) lines->children_accept(guest);
    if(else_stmt != nullptr) else_stmt->children_accept(guest);
    accept(guest);
}

} /* namespace ast */