#ifndef AST_CONDITIONAL_HPP
#define AST_CONDITIONAL_HPP

#include "tree.hpp"
#include "expr.hpp"
#include "funcall.hpp"

namespace ast {

class conditional;
typedef std::shared_ptr<conditional> conditional_p;
class lr_conditional;
typedef std::shared_ptr<lr_conditional> lr_conditional_p;
class funcall_conditional;
typedef std::shared_ptr<funcall_conditional> funcall_conditional_p;

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

protected:
    virtual bool do_compare() = 0;
    
    /* members */
public:
    bool inverse;
}; /* class conditional */


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
protected:
    virtual bool do_compare() { return false; }

    /* members */
public:
    const expr_p left;
    const expr_p right;
}; /* class lr_conditional */


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
protected:
    virtual bool do_compare() { return false; }

    /* members */
public:
    const funcall_p funcall;
}; /* class funcall_conditional */

} /* namespace ast */
#endif