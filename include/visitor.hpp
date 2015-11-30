#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "ast/tree.hpp"

class visitor
{
public:
    virtual ~visitor() = 0;

public:
    virtual void visit(ast::tree&) { };
    virtual void visit(ast::exec&) { };
    virtual void visit(ast::conditional&) { };
    virtual void visit(ast::expr&) { };
    virtual void visit(ast::for_stmt&) { };
    virtual void visit(ast::if_stmt&) { };
    virtual void visit(ast::string_expr&) { };
    virtual void visit(ast::number_expr&) { };
    virtual void visit(ast::dimension&) { };
    virtual void visit(ast::range&) { };
    virtual void visit(ast::funcall&) { };
    virtual void visit(ast::args_list&) { };
    virtual void visit(ast::qualified_id&) { };
};

#endif