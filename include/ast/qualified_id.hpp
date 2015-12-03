#ifndef AST_QUALIFIED_ID_HPP
#define AST_QUALIFIED_ID_HPP

#include "expr.hpp"

namespace ast {

class qualified_id;
typedef std::shared_ptr<qualified_id> qualified_id_p;

class qualified_id 
    : public expr
{
public:
    qualified_id(cstref value, qualified_id_p tail)
        : value(value)
        , tail(tail) { }
    virtual ~qualified_id() = default;

public:
    virtual void children_accept(visitor* guest)
    {
        accept(guest);
        if(tail != nullptr)
            tail->children_accept(guest);
    }

public:
    std::string value;
    qualified_id_p tail;
};

} /* namespace ast */
#endif