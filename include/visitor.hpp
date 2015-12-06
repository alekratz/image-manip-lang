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
    virtual void visit(ast::lr_conditional*) { std::cout << "lr_conditional" << std::endl; }
    virtual void visit(ast::funcall_conditional* node)
        { std::cout << "funcall_conditional: " << node->funcall->args->size() << " args" << std::endl; }
    virtual void visit(ast::for_stmt* node) 
        { std::cout << "for_stmt: varname: " << node->varname << ", line count: " << node->lines->size() << std::endl; }
    virtual void visit(ast::if_stmt* node)
        { std::cout << "if_stmt: line count: " << node->lines->size() << std::endl; }
    virtual void visit(ast::else_stmt* node)
        { std::cout << "else_stmt: line count: " << node->lines->size() << std::endl; }
    virtual void visit(ast::string_expr* node)
        { std::cout << "string_expr: " << node->value << std::endl; }
    virtual void visit(ast::number_expr* node)
        { std::cout << "number_expr: " << node->value << std::endl; }
    virtual void visit(ast::dimension* node)
        { std::cout << "dimension: " << node->first << ", " << node->second << std::endl; }
    virtual void visit(ast::range* node)
        { std::cout << "range: " << node->start << ", " << node->end << std::endl; }
    virtual void visit(ast::funcall* node)
        { std::cout << "funcall:" << node->args->size() << " args" << std::endl; }
    virtual void visit(ast::args_list* node)
        { std::cout << "args_list: " << node->members.size() << " args" << std::endl; }
    virtual void visit(ast::line_list* node)
        { std::cout << "line_list: " << node->members.size() << " lines" << std::endl; }
    virtual void visit(ast::qualified_id* node)
        { std::cout << "qualified_id" << node->str() << std::endl; }
};

#endif