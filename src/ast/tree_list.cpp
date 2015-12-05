#include "ast/tree_list.hpp"
#include "visitor.hpp"

namespace ast {

/*
void args_list::accept(visitor* guest)
{
    guest->visit(this);
}

void line_list::accept(visitor* guest)
{
    guest->visit(this);
} */

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
/*
void args_list::traverse_top_down(visitor* guest)
{
    accept(guest);
    base_t::traverse_top_down(guest);
}

void args_list::traverse_bottom_up(visitor* guest)
{
    base_t::traverse_bottom_up(guest);
    accept(guest);
}

void line_list::traverse_top_down(visitor* guest)
{
    accept(guest);
    base_t::traverse_top_down(guest);
}

void line_list::traverse_bottom_up(visitor* guest)
{
    base_t::traverse_bottom_up(guest);
    accept(guest);
} */


} /* namespace ast */