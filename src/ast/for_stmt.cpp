#include "ast.hpp"
#include "visitor.hpp"

namespace ast {
void for_stmt::children_accept(visitor* guest)
{
    accept(guest);
    if(range != nullptr) range->accept(guest);
    if(lines != nullptr) lines->accept(guest);
}
} /* namespace ast */