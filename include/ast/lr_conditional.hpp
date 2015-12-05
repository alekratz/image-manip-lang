#ifndef LR_CONDITIONAL
#define LR_CONDITIONAL

#include "conditional.hpp"

namespace ast {

class lr_conditional;
typedef std::shared_ptr<lr_conditional> lr_conditional_p;

class lr_conditional
    : public conditional
{
public:
    lr_conditional(expr_p left, expr_p right)
        : conditional()
        , left(left)
        , right(right) {  }
    virtual ~lr_conditional() = default;

    /* operations */
public:
    virtual void accept(visitor* guest);
    virtual void children_accept(visitor* guest);
    virtual void traverse_top_down(visitor* guest);
    virtual void traverse_bottom_up(visitor* guest);
protected:
    virtual bool do_compare() { return false; }

    /* members */
public:
    const expr_p left;
    const expr_p right;
}; /* class lr_conditional */

} /* namespace ast */
#endif