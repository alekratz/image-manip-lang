#include "ast/tree_list.hpp"
#include "visitor.hpp"

namespace ast {

void args_list::children_accept(visitor* guest)
{
    accept(guest);
    base_t::children_accept(guest);
}

void line_list::children_accept(visitor* guest)
{
    accept(guest);
    base_t::children_accept(guest);
}

} /* namespace ast */