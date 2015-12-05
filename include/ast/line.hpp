#ifndef AST_LINE_HPP
#define AST_LINE_HPP

#include "tree.hpp"
#include <vector>
#include <sstream>

namespace ast {

class line;
typedef std::shared_ptr<line> line_p;

class line
    : public virtual tree
{
public:
    line() = default;
    virtual ~line() = 0;

public:
    virtual void accept(visitor* guest) = 0;
    virtual void children_accept(visitor* guest) = 0;
    virtual void traverse_top_down(visitor* guest) = 0;
virtual void traverse_bottom_up(visitor* guest) = 0;
    virtual void operator()() = 0;
};

} /* namespace ast */

#endif