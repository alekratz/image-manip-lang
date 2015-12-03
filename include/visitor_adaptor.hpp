#ifndef VISITOR_ADAPTOR_HPP
#define VISITOR_ADAPTOR_HPP

class visitor;
class visitor_adaptor
{
public:
    virtual ~visitor_adaptor() = 0;

public:
    void accept(visitor* guest);
    virtual void children_accept(visitor* guest) { accept(guest); }
};

#endif