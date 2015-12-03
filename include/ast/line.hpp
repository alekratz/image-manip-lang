#ifndef AST_LINE_HPP
#define AST_LINE_HPP

#include "tree.hpp"
#include <vector>
#include <sstream>

namespace ast {

class line;
typedef std::shared_ptr<line> line_p;
typedef std::vector<line_p> line_p_list;

class line
    : public virtual tree
{
public:
    line() = default;
    virtual ~line() = 0;

public:
    virtual void accept(visitor* guest) = 0;
    virtual void operator()() = 0;
};

} /* namespace ast */

#endif