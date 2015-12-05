#ifndef FUNCALL_CONDITIONAL_HPP
#define FUNCALL_CONDITIONAL_HPP

#include "conditional.hpp"

namespace ast {

class funcall_conditional;
typedef std::shared_ptr<funcall_conditional> funcall_conditional_p;

class funcall_conditional
    : public conditional
{
public:
    funcall_conditional(funcall_p funcall)
        : conditional()
        , funcall(funcall) { }
    virtual ~funcall_conditional() = default;

    /* operations */
public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest);
protected:
    virtual bool do_compare() { return false; }

    /* members */
public:
    const funcall_p funcall;
}; /* class funcall_conditional */

} /* namespace ast */
#endif