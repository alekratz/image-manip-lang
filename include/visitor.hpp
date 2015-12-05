#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "ast.hpp"
#include <iostream>

class visitor
{
public:
    virtual ~visitor() = 0;

public:
    virtual void traverse_top_down(ast::tree* root) { root->traverse_top_down(this); }
    virtual void traverse_bottom_up(ast::tree* root) { root->traverse_bottom_up(this); }

public:
    virtual void visit(ast::line*) { }
    virtual void visit(ast::lr_conditional*) { }
    virtual void visit(ast::funcall_conditional*) { }
    virtual void visit(ast::for_stmt*) { }
    virtual void visit(ast::if_stmt*) { }
    virtual void visit(ast::else_stmt*) { }
    virtual void visit(ast::string_expr*) { }
    virtual void visit(ast::number_expr*) { }
    virtual void visit(ast::dimension*) { }
    virtual void visit(ast::range*) { }
    virtual void visit(ast::funcall*) { }
    virtual void visit(ast::args_list*) { }
    virtual void visit(ast::line_list*) { }
    virtual void visit(ast::qualified_id*) { }
};

class printout_visitor
    : public visitor
{
public:
    virtual ~printout_visitor() = default;

public:
    virtual void visit(ast::line*) { std::cout << "line" << std::endl; }
    virtual void visit(ast::lr_conditional*) { std::cout << "lr_conditional" << std::endl; }
    virtual void visit(ast::funcall_conditional*) { std::cout << "funcall_conditional" << std::endl; }
    virtual void visit(ast::for_stmt*) { std::cout << "for_stmt" << std::endl; }
    virtual void visit(ast::if_stmt*) { std::cout << "if_stmt" << std::endl; }
    virtual void visit(ast::else_stmt*) { std::cout << "else_stmt" << std::endl; }
    virtual void visit(ast::string_expr*) { std::cout << "string_expr" << std::endl; }
    virtual void visit(ast::number_expr*) { std::cout << "number_expr" << std::endl; }
    virtual void visit(ast::dimension*) { std::cout << "dimension" << std::endl; }
    virtual void visit(ast::range*) { std::cout << "range" << std::endl; }
    virtual void visit(ast::funcall*) { std::cout << "funcall" << std::endl; }
    virtual void visit(ast::args_list*) { std::cout << "args_list" << std::endl; }
    virtual void visit(ast::line_list*) { std::cout << "line_list" << std::endl; }
    virtual void visit(ast::qualified_id*) { std::cout << "qualified_id" << std::endl; }
};

#endif