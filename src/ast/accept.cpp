#include "ast.hpp"
#include "visitor.hpp"

#define ACCEPT_DECL(classname) void classname::accept(visitor* guest) { guest->visit(this); }

namespace ast {

ACCEPT_DECL(line)
ACCEPT_DECL(lr_conditional)
ACCEPT_DECL(funcall_conditional)
ACCEPT_DECL(for_stmt)
ACCEPT_DECL(if_stmt)
ACCEPT_DECL(else_stmt)
ACCEPT_DECL(string_expr)
ACCEPT_DECL(number_expr)
ACCEPT_DECL(dimension)
ACCEPT_DECL(range)
ACCEPT_DECL(qualified_id)
ACCEPT_DECL(args_list)
ACCEPT_DECL(line_list)
ACCEPT_DECL(funcall)
}