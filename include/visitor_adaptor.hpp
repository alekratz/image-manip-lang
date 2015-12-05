#ifndef VISITOR_ADAPTOR_HPP
#define VISITOR_ADAPTOR_HPP

// #include "visitor.hpp"

class visitor;

class visitor_adaptor
{
public:
    virtual void accept(visitor* guest) = 0;
    virtual void children_accept(visitor* guest) = 0;
    virtual void traverse_top_down(visitor* guest) = 0;
    virtual void traverse_bottom_up(visitor* guest) = 0;
};

#endif