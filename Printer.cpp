#include "Printer.h"

#include <string>
#include <iostream>

void Printer::printParamsError(int const& paramsLen, int const& needed){
    if(paramsLen < needed){
        std::cout << " Error: not enough parameters (" << paramsLen << ").\n type help to see the list of commands." << std::endl;
    }else if(paramsLen > needed){
        std::cout << " Error: too many parameters (" << paramsLen << ").\n type help to see the list of commands." << std::endl;
    }else if(needed == 0){
        std::cout << " Error: parameters error (" << paramsLen << ").\n type help to see the list of commands." << std::endl;
    }
}

void Printer::successCreated(std::string const& var, std::string const& path, std::string const& type){
    std::cout << " Successfully added var \"" << var << "\" connecting to the path " << path << " with method " << type << "." << std::endl;
}

void Printer::successEnvCreated(std::string const& var, std::string const& path, std::string const& level){
    std::cout << " Successfully added environment-var \"" << var << "\" with path " << path << ". (" << level << ")" << std::endl;
}

void Printer::typeError(std::string const& type, std::string const& var){
    std::cout << " Error while aptempting to create var \"" << var << "\", type must be exec or cd (" << type << ")." << std::endl;
}

void Printer::unknwCmd(std::string const& cmd){
    std::cout << " Error: unknown command (" << cmd << ") please type help to see the list of commands." << std::endl;
}

void Printer::unknwSubCmd(std::string const& scmd){
    std::cout << " Error: unknown sub-command (" << scmd << ") please type help to see the list of commands." << std::endl;
}

void Printer::deleteVar(std::string const& var){
    std::cout << " Successfully removed var \"" << var << "\" !" << std::endl;
}

void Printer::doesNotExists(std::string const& var){
    std::cout << " Error: var \"" << var << "\" does not exist." << std::endl;
}

void Printer::couldNotLoadFile(){
    std::cout << " Error: Could not load the file." << std::endl;
}

void Printer::couldNotSaveFile(){
    std::cout << " Error: Could not save the file." << std::endl;
}

void Printer::fetchVar(std::string const& var, std::string const& path, std::string const& type){
    std::cout << std::endl << " + Fetched var \"" << var << "\" connecting to path " << path << " with method " << type << "."  << std::endl;
}

void Printer::fetchEnv(std::string const& var, std::string const& path, std::string const& type){
    std::cout << std::endl << " + Fetched environment-var \"" << var << "\" with path " << path << ". (" << type << ")"  << std::endl;
}

void Printer::savedFile(std::string const& path){
    std::cout << " Saved file to path: " << path << "." << std::endl;
}

void Printer::notFound(std::string const& var){
    std::cout << " Error: did not find the environment-var \"" << var << "\"." << std::endl;
}

void Printer::successRemoved(std::string const& var){
    std::cout << " Successfully removed the environment-var \"" << var << "\"." << std::endl;
}
