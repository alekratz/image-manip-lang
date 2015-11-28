%option c++ noyywrap nounput batch debug noinput

%{
#include "imdriver.hpp"
#include "imlexer.hpp"
#include "parser.hpp"

#include <sstream>
#include <string>
#include <cstdint>

#define YY_USER_ACTION loc.columns(yyleng);

# undef yywrap
# define yywrap() 1
%}

L           [a-zA-Z_]
D           [0-9]
H           {D}|[a-fA-F]

identifier  {L}({L}|{D})*
num         {D}+
comment     #.*{newline}
newline     \n+
ws          [\t ]

%%

%{
    loc.step();
%}

{comment}       loc.lines(1);
{newline}       {
    loc.lines(yyleng);
    loc.step();
    return yy::imparser::make_NEWLINE(loc);
}
{ws}            loc.step();
end             return yy::imparser::make_END_KEYW(loc);
for             return yy::imparser::make_FOR_KEYW(loc);
in              return yy::imparser::make_IN_KEYW(loc);
if              return yy::imparser::make_IF_KEYW(loc);

\.              return yy::imparser::make_DOT(loc);
\.\.            return yy::imparser::make_DOUBLEDOT(loc);
\*              return yy::imparser::make_STAR(loc);
\(              return yy::imparser::make_LPAREN(loc);
\)              return yy::imparser::make_RPAREN(loc);
x               return yy::imparser::make_DIM_SEP(loc);
!               return yy::imparser::make_BANG(loc);

\"[^\"\n]*\"    return yy::imparser::make_STRING(yytext, loc);
{identifier}    return yy::imparser::make_IDENTIFIER(yytext, loc);
{num}           {
    std::stringstream stream(yytext);
    int64_t result;
    stream >> result;
    return yy::imparser::make_NUMBER(result, loc);
}
@{H}+           {
    std::stringstream stream;
    stream << std::hex << yytext + 1;
    int64_t result;
    stream >> result;
    return yy::imparser::make_COLOR(result, loc);
}

.               { driver.error(loc, "unexpected character", yytext); }

%%

int yyFlexLexer::yylex()
{
    assert(false && "yyFlexLexer::yylex() called; this should not happen");
    return 0;
}

