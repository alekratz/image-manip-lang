#include "ast.hpp"
#include "visitor.hpp"

namespace ast {
tree::~tree() { }

void tree::accept(visitor* guest)
    { guest->visit(*this); }

} /* namespace ast */