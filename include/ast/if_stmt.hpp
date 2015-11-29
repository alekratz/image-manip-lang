#ifndef AST_IF_STMT_HPP
#define AST_IF_STMT_HPP

#include "exec.hpp"
#include "expr.hpp"

namespace ast {

class if_stmt;
typedef std::shared_ptr<if_stmt> if_stmt_p;
class else_stmt;
typedef std::shared_ptr<else_stmt> else_stmt_p;

class else_stmt
    : public exec
{
public:
    else_stmt(line_list_p lines)
        : lines(lines) { }
    virtual ~else_stmt() = default;

public:
    line_list_p lines;

    virtual void operator()()
    {
        for(const auto& line : lines->members) (*line)();
    }
};

class if_stmt 
    : public exec
{
public:
    if_stmt(conditional_p conditional, line_list_p lines, else_stmt_p else_stmt)
        : conditional(conditional)
        , lines(lines)
        , else_stmt(else_stmt) 
        { }
    virtual ~if_stmt() = default;

public:
    conditional_p conditional;
    line_list_p lines;
    else_stmt_p else_stmt;

    virtual void operator()()
    {
        if(conditional->compare())
            for(const auto& line : lines->members) (*line)();
        else if(else_stmt != nullptr)
            (*else_stmt)();
    }
};

} /* namespace ast */
#endif