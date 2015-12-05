#ifndef AST_CONDITIONAL_HPP
#define AST_CONDITIONAL_HPP

#include "tree.hpp"
#include "expr.hpp"
#include "funcall.hpp"

namespace ast {

class conditional;
typedef std::shared_ptr<conditional> conditional_p;

class conditional 
    : public virtual tree
{
    /* ctor/dtor */
public:
    conditional()
        : inverse(false) { }
    virtual ~conditional() = 0;

    /* operations */
public:
    bool compare() { return inverse ? !do_compare() : do_compare(); }
    virtual void accept(visitor* guest) = 0;
    virtual void children_accept(visitor* guest) = 0;
    virtual void traverse_top_down(visitor* guest) = 0;
    virtual void traverse_bottom_up(visitor* guest) = 0;

protected:
    virtual bool do_compare() = 0;
    
    /* members */
public:
    bool inverse;
}; /* class conditional */

} /* namespace ast */
#endif