#include "ast/qualified_id.hpp"
#include "visitor.hpp"

namespace ast {

void qualified_id::children_accept(visitor* guest)
{
    accept(guest);
    if(tail != nullptr) tail->accept(guest);
}

} /* namespace ast */