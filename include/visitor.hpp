#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "ast/tree.hpp"
#include <iostream>

class visitor
{
public:
    virtual ~visitor() = 0;

public:
    virtual void traverse_top_down(ast::tree& root) { root.children_accept(this); }

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

class printout_visitor
    : public visitor
{
public:
    virtual ~printout_visitor() = default;

public:
    virtual void visit(ast::tree&) { std::cout << "tree" << std::endl; };
    virtual void visit(ast::exec&) { std::cout << "exec" << std::endl; };
    virtual void visit(ast::conditional&) { std::cout << "conditional" << std::endl; };
    virtual void visit(ast::expr&) { std::cout << "expr" << std::endl; };
    virtual void visit(ast::for_stmt&) { std::cout << "for_stmt" << std::endl; };
    virtual void visit(ast::if_stmt&) { std::cout << "if_stmt" << std::endl; };
    virtual void visit(ast::string_expr&) { std::cout << "string_expr" << std::endl; };
    virtual void visit(ast::number_expr&) { std::cout << "number_expr" << std::endl; };
    virtual void visit(ast::dimension&) { std::cout << "dimension" << std::endl; };
    virtual void visit(ast::range&) { std::cout << "range" << std::endl; };
    virtual void visit(ast::funcall&) { std::cout << "funcall" << std::endl; };
    virtual void visit(ast::args_list&) { std::cout << "args_list" << std::endl; };
    virtual void visit(ast::qualified_id&) { std::cout << "qualified_id" << std::endl; };
};

#endif