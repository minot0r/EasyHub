#include "Parser.h"
#include "Utils.h"

#include <string>
#include <vector>>

std::string Parser::getPath(std::string const& args){
    std::string temp(args);
    std::string path;
    if(!Utils::contains(temp, "\"")){
        std::vector<std::string> args = Utils::split(temp, ' ');
        return args[2];
    }
}

std::string Parser::getType(std::string const& args){
    std::string temp(args);
    std::string path;
    if(!Utils::contains(temp, "\"")){
        std::vector<std::string> args = Utils::split(temp, ' ');
        return args[3];
    }
}

std::string Parser::getVarName(std::string const& args){
    std::string temp(args);
    std::string path;
    if(!Utils::contains(temp, "\"")){
        std::vector<std::string> args = Utils::split(temp, ' ');
        return args[1];
    }
}
