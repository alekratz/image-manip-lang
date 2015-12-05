#include "ast/else_stmt.hpp"
#include "visitor.hpp"

namespace ast {

void else_stmt::children_accept(visitor* guest)
{
    accept(guest);
    if(lines != nullptr) lines->accept(guest);
}

} /* namespace ast */