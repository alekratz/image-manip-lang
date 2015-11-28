%option c++ noyywrap nounput batch debug noinput

%{
#include <string>
#include "imdriver.hpp"
#include "imlexer.hpp"
#include "parser.hpp"

#define YY_USER_ACTION loc.columns(yyleng);

# undef yywrap
# define yywrap() 1
%}

L           [a-zA-Z_]
D           [0-9]
H           {D}|[a-fA-F]

identifier  {L}({L}|{D})*
comment     #.*$
newline     \n+
ws          [\t ]

%%

%{
    loc.step();
%}

{comment}       loc.step();
{newline}       { loc.lines(yyleng); loc.step(); }
{ws}            loc.step();
end             return yy::imparser::make_END_KEYW(loc);
for             return yy::imparser::make_FOR_KEYW(loc);
if              return yy::imparser::make_IF_KEYW(loc);

\.              return yy::imparser::make_DOT(loc);
\*              return yy::imparser::make_STAR(loc);
\(              return yy::imparser::make_LPAREN(loc);
\)              return yy::imparser::make_RPAREN(loc);

\"[^\"\n]*\"    return yy::imparser::make_STRING(yytext, loc);
{identifier}    return yy::imparser::make_IDENTIFIER(yytext, loc);

.               { driver.error(loc, "unexpected character", yytext); }

%%

int yyFlexLexer::yylex()
{
    assert(false && "yyFlexLexer::yylex() called; this should not happen");
    return 0;
}

