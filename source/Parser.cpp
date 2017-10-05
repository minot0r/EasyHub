#include "../includes/Parser.h"
#include "../includes/Utils.h"

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

std::string Parser::getBrackPath(std::string const& str){
    return str.substr(Utils::getFirst(str, '"')+1, Utils::getLast(str, '"')-Utils::getFirst(str, '"')-1);
}

std::string Parser::subtractBrackPath(std::string str){
    std::string clone = str;
    str = str.substr(0, Utils::getFirst(str, '"'));
    str = str + clone.substr(Utils::getLast(clone, '"')+1, clone.length());
    return str;
}
