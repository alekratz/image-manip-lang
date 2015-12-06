#include "ast/funcall.hpp"
#include "visitor.hpp"

namespace ast {
void funcall::children_accept(visitor* guest)
{
    accept(guest);
    if(args != nullptr) args->accept(guest);
}

void funcall::traverse_top_down(visitor* guest)
{
    accept(guest);
    if(args != nullptr) args->traverse_top_down(guest);
}

void funcall::traverse_bottom_up(visitor* guest)
{
    if(args != nullptr) args->traverse_bottom_up(guest);
    accept(guest);
}

} /* namespace ast */