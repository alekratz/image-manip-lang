#include "ast.hpp"
#include "visitor.hpp"

#define VISITOR_ACCEPT_DECL(classname) void classname::accept(visitor* guest) { guest->visit(this); }

namespace ast {

VISITOR_ACCEPT_DECL(line)
VISITOR_ACCEPT_DECL(lr_conditional)
VISITOR_ACCEPT_DECL(funcall_conditional)
VISITOR_ACCEPT_DECL(for_stmt)
VISITOR_ACCEPT_DECL(if_stmt)
VISITOR_ACCEPT_DECL(else_stmt)
VISITOR_ACCEPT_DECL(string_expr)
VISITOR_ACCEPT_DECL(number_expr)
VISITOR_ACCEPT_DECL(dimension)
VISITOR_ACCEPT_DECL(range)
VISITOR_ACCEPT_DECL(qualified_id)
VISITOR_ACCEPT_DECL(args_list)
VISITOR_ACCEPT_DECL(line_list)
VISITOR_ACCEPT_DECL(funcall)

}