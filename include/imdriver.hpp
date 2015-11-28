#ifndef IMDRIVER_HPP
#define IMDRIVER_HPP

#include "parser.hpp"
#include "imlexer.hpp"

#include <string>

class imdriver
{
public:
    imdriver()
        : streamname()
        , lexer(nullptr)
        , trace_scanning(false)
        , trace_parsing(false)
    { }
    virtual ~imdriver() = default;

public:
    bool parse_stream(std::istream& in, const std::string& sname, std::ostream& out=std::cout);
    //bool parse_string(const std::string& line, const std::string& sname, std::ostream& out=std::cout);
    bool parse_file(const std::string& f, std::ostream& out=std::cout);
    void error (const yy::location& l, const std::string& m, const std::string& t);
    void error (const yy::location& l, const std::string& m);
    void error (const std::string& m);

    /* members */
public:
    std::string streamname;
    imlexer *lexer;
    bool trace_scanning;
    bool trace_parsing;
};

#endif