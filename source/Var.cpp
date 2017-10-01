#include "../includes/Var.h"

#include <string>

std::string Var::getName() const{
    return name;
}

std::string Var::getPath() const{
    return path;
}

std::string Var::getType() const{
    return type;
}

Var::Var(std::string varName, std::string path, std::string type){
    name = varName;
    this->path = path;
    this->type = type;
}
