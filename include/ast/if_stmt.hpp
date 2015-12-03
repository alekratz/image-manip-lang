#ifndef AST_IF_STMT_HPP
#define AST_IF_STMT_HPP

#include "line.hpp"
#include "expr.hpp"

namespace ast {

class if_stmt;
typedef std::shared_ptr<if_stmt> if_stmt_p;
class else_stmt;
typedef std::shared_ptr<else_stmt> else_stmt_p;

class else_stmt
    : public line
{
    /* ctor/dtor */
public:
    else_stmt(line_list_p lines)
        : lines(lines) { }
    virtual ~else_stmt() = default;

    /* operations */
public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest)
    {
        accept(guest);
        if(lines != nullptr) lines->children_accept(guest);
    }

    virtual void operator()()
    {
        for(const auto& line : lines->members) (*line)();
    }
    /* members */
public:
    line_list_p lines;
};

class if_stmt 
    : public line
{
    /* ctor/dtor */
public:
    if_stmt(conditional_p conditional, line_list_p lines, else_stmt_p else_stmt)
        : conditional(conditional)
        , lines(lines)
        , else_stmt(else_stmt) 
        { }
    virtual ~if_stmt() = default;

    /* operations */
public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest)
    {
        accept(guest);
        if(conditional != nullptr) conditional->children_accept(guest);
        if(lines != nullptr) lines->children_accept(guest);
        if(else_stmt != nullptr) else_stmt->children_accept(guest);
    }

    virtual void operator()()
    {
        if(conditional->compare())
            for(const auto& line : lines->members) (*line)();
        else if(else_stmt != nullptr)
            (*else_stmt)();
    }
    /* members */
public:
    conditional_p conditional;
    line_list_p lines;
    else_stmt_p else_stmt;
};

} /* namespace ast */
#endif