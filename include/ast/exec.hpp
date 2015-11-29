#ifndef AST_EXEC_HPP
#define AST_EXEC_HPP

#include "tree.hpp"
#include <vector>
#include <sstream>

namespace ast {

class exec;
typedef std::shared_ptr<exec> exec_p;
typedef std::vector<exec_p> exec_p_list;

class exec
    : public tree
{
public:
    exec() = default;
    virtual ~exec() = 0;

public:
    virtual void operator()() = 0;
};

} /* namespace ast */

#endif