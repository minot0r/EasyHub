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
    }else{

    }
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
