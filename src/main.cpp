#include "imdriver.hpp"
#include "visitor.hpp"

#include <getopt.h>
#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>

#define VCOUT if(verbose) cout
#define VCERR if(verbose) cerr

using namespace std;
namespace fs = boost::filesystem;

static bool trace_scanning = false;
static bool trace_parsing = false;
static bool verbose = false;
static vector<string> filenames;

static bool parse_opts(int, char**);
static void usage(int, char**);

static bool parse_opts(int argc, char **argv)
{
    static struct option lopts[] = 
    {
        { "trace-scanning", no_argument, nullptr, 's' },
        { "trace-parsing",  no_argument, nullptr, 'p' },
        { "verbose",        no_argument, nullptr, 'v' },
        { nullptr, 0, nullptr, 0 },
    };

    char c;
    int option_index;
    while((c = getopt_long(argc, argv, "spv", lopts, &option_index)) != -1)
    {
        switch(c)
        {
            // GNU will print out the error for us
            case '?': return false;
            case 'v':
                verbose = true;
                break;
            case 's':
                trace_scanning = true;
                break;
            case 'p':
                trace_parsing = true;
                break;
            default:
                break;
        }
    }
    while(optind < argc)
        filenames.push_back(argv[optind++]);
    for(; optind < argc; optind++)
        cerr << "ignoring input file: " << argv[optind] << endl;
    return true;
}

static void usage(int argc, char **argv)
{
    cout << "usage: " << argv[0] << " [options] file [ file ... ]" << endl;
    cout << "available options: " << endl;
    cout << endl <<
"-s | --trace-scanning                      traces the scanning of the input " << endl <<
"-p | --trace-parsing                       traces the parsing of the input  " << endl <<
"-v | --verbose                             verbose output                   " << endl <<
    endl;
}

int main(int argc, char **argv)
{
    if(parse_opts(argc, argv) == 0)
    {
        // GNU prints the error for us
        usage(argc, argv);
        cerr << "exiting" << endl;
        exit(1);
    }

    if(filenames.size() == 0)
    {
        cerr << argv[0] << " requires at least one argument" << endl;
        usage(argc, argv);
        cerr << "exiting" << endl;
        exit(1);
    }

    for(auto& file : filenames)
    {
        VCOUT << "processing file " << file << ": ";
        imdriver the_driver;
        the_driver.trace_scanning = trace_scanning;
        the_driver.trace_parsing = trace_parsing;
        if(!fs::exists(file) || fs::is_directory(file))
        {
            VCOUT << endl;
            cerr << "error: `" << file << "' is not a regular file" << endl;
            cerr << "exiting" << endl;
            exit(1);
        }
        if(the_driver.parse_file(file))
        {
            if(the_driver.parsed_ast != nullptr)
            {
                printout_visitor guest;
                guest.traverse_top_down(the_driver.parsed_ast.get());
                VCOUT << "done" << endl;
            }
            else
                VCOUT << "file empty, skipping" << endl;
        }
    }

    return 0;
}

