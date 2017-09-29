#include "Printer.h"

#include <string>
#include <iostream>

void Printer::printParamsError(int const& paramsLen, int const& needed){
    if(paramsLen < needed){
        std::cout << " Error: not enough parameters (" << paramsLen << ").\n type help to see the list of commands." << std::endl;
    }else{
        std::cout << " Error: too many parameters (" << paramsLen << ").\n type help to see the list of commands." << std::endl;
    }
}

void Printer::successCreated(std::string const& var, std::string const& path, std::string const& type){
    std::cout << " Successfully added var \"" << var << "\" connecting to the path " << path << " with method " << type << "." << std::endl;
}

void Printer::typeError(std::string const& type, std::string const& var){
    std::cout << " Error while aptempting to create var \"" << var << "\", type must be exec or cd (" << type << ")." << std::endl;
}

void Printer::unknwCmd(std::string const& cmd){
    std::cout << " Error: unknown command (" << cmd << ") please type help to see the list of commands." << std::endl;
}

void Printer::deleteVar(std::string const& var){
    std::cout << " Successfully removed var \"" << var << "\" !" << std::endl;
}

void Printer::doesNotExists(std::string const& var){
    std::cout << " Error: var \"" << var << "\" does not exist." << std::endl;
}

void Printer::couldNotLoadFile(){
    std::cout << " Could not load the file." << std::endl;
}
