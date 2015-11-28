#ifndef IMLEXER_HPP
#define IMLEXER_HPP

#include "imdriver.hpp"
#include "parser.hpp"

#ifndef __FLEX_LEXER_H
#define yyFlexLexer yyFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
#endif

#define YY_DECL \
    yy::imparser::symbol_type imlexer::lex(imdriver& driver)
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
    yy::imparser::symbol_type lex(imdriver& driver);
    // Location of the current token
    yy::location loc;

};

#endif