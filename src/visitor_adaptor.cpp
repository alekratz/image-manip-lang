#include "visitor_adaptor.hpp"
#include "visitor.hpp"

visitor_adaptor::~visitor_adaptor()
    { }

void visitor_adaptor::accept(visitor* guest)
    { guest->visit(this); }