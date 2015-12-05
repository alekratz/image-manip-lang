#ifndef ELSE_STMT_HPP
#define ELSE_STMT_HPP

#include "line.hpp"
#include "tree_list.hpp"

namespace ast {

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
    virtual void children_accept(visitor* guest);

    virtual void operator()()
    {
        for(const auto& line : lines->members) (*line)();
    }
    /* members */
public:
    line_list_p lines;
};

} /* namespace ast */
#endif