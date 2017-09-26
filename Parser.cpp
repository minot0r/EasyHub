#include "Parser.h"
#include "Utils.h"

#include <string>
#include <vector>>

std::string Parser::getPath(std::string const& args){
    std::string temp(args);
    std::string path;
    std::vector<std::string> vec = Utils::split(temp, ' ');
    return vec[2];
}

std::string Parser::getType(std::string const& args){
    std::string temp(args);
    std::string path;
    std::vector<std::string> arr = Utils::split(temp, ' ');
    return arr[3];
}

std::string Parser::getVarName(std::string const& args){
    std::string temp(args);
    std::string path;
    std::vector<std::string> arr = Utils::split(temp, ' ');
    return arr[1];
}
