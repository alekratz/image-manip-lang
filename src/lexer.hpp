#include "imdriver.hpp"
#include "imparser.hpp"

#ifndef __FLEX_LEXER_H
#define yyFlexLexer yyFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
#endif

#define YY_DECL \
    yy::imparser::symbol_type imlexer::lex(lisplike_driver& driver)
#define yyterminate() return yy::imparser::make_END(loc);

class yyFlexLexer;

class imlexer
    : public yyFlexLexer
{
public:
    imlexer(std::istream *in = nullptr, std::ostream *out = nullptr)
        : yyFlexLexer(in, out)
    { }

public:
    yy::imparser::symbol_type lex(lisplike_driver& driver);
    yy::location loc;

protected:
    //lisplike_driver& driver;
};