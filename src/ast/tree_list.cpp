#include "ast/tree_list.hpp"
#include "visitor.hpp"

namespace ast {

void args_list::children_accept(visitor* guest)
{
    base_t::accept(guest);
}

void line_list::children_accept(visitor* guest)
{
    base_t::accept(guest);
}


} /* namespace ast */