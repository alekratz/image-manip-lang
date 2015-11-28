#include "imdriver.hpp"
#include "imlexer.hpp"
#include "parser.hpp"
#include <string>
#include <fstream>

using namespace std;

bool imdriver::parse_stream(istream& in, const string& sname, ostream& out)
{
    //reset();
    streamname = sname;
    imlexer scanner(&in);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;
    yy::imparser parser(*this);
    parser.set_debug_level(trace_parsing);
    bool success = parser.parse() == 0;
    lexer = nullptr; // it's only active on the stack
    return success;
}

/*
bool imdriver::parse_string(const string& line, const string& sname, std::ostream& out)
{
    istringstream iss(line);
    return parse_stream(iss, sname);
}
*/

bool imdriver::parse_file(const string& filename, std::ostream& out)
{
    ifstream in(filename);
    if(!in.good()) return false;
    return parse_stream(in, filename);
}

void imdriver::error(const yy::location& l, const std::string& m, const std::string& t)
{
    cerr << streamname << ":" << l << ": " << m << ": " << t << endl;
}

void imdriver::error(const yy::location& l, const string& m)
{
    cerr << streamname << ":" << l << ": " << m << endl;
}

void imdriver::error (const string& m)
{
    cerr << streamname << ":" << m << endl;
}