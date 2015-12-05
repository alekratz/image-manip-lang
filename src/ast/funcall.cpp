#include "ast/funcall.hpp"
#include "visitor.hpp"

namespace ast {
void funcall::children_accept(visitor* guest)
{
    accept(guest);
    if(args != nullptr) args->accept(guest);
}

} /* namespace ast */