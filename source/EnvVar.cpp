#include "../includes/EnvVar.h"

#include <string>

std::string EnvVar::getName() const{
    return name;
}

std::string EnvVar::getPath() const{
    return path;
}

std::string EnvVar::getLevel() const{
    return level;
}


EnvVar::EnvVar(std::string varName, std::string path, std::string level){
    name = varName;
    this->path = path;
    this->level = level;
}
