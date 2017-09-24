#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <string>

class Parser{

    public:
        static std::string getPath(std::string const& args);
        static std::string getType(std::string const& args);
        static std::string getVarName(std::string const& args);

};

#endif // PARSER_H_INCLUDED
