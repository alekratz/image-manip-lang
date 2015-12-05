#include "ast/funcall_conditional.hpp"
#include "visitor.hpp"

namespace ast {

void funcall_conditional::children_accept(visitor* guest)
{
    accept(guest);
    if(funcall != nullptr) funcall->accept(guest);
}

} /* namespace ast */