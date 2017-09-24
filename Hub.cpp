#include "Hub.h"
#include "Utils.h"
#include "Parser.h"


#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

void ConsoleHub::affMsg(){

    std::string display =
        "  ______                _    _       _     \n"
        " |  ____|              | |  | |     | |    \n"
        " | |__   __ _ ___ _   _| |__| |_   _| |__  \n"
        " |  __| / _` / __| | | |  __  | | | | '_ \\ \n"
        " | |___| (_| \\__ \\ |_| | |  | | |_| | |_) |\n"
        " |______\\__,_|___/\\__, |_|  |_|\\__,_|_.__/ \n"
        "                   __/ |                   \n"
        "                  |___/                    \n"
        "\n\n";

    std::string help = " | define a new var to the hub with: define varname path type [cd, exec]\n"
    " | load a created var with load varname\n"
    " | finally delete a var with delete varname\n\n";

    std::cout << display << std::endl << help << std::endl;


}

void ConsoleHub::defineNew(std::string const& args){
    std::vector<std::string> eachArgs (Utils::split(args, ' '));
    if(eachArgs.size() == 4){
        std::string type(Parser::getType(args));
        std::string varName(Parser::getVarName(args));
        std::string path(Parser::getPath(args));

        if(type == "cd" || type == "exec"){
            ConsoleHub::definedVars[varName][path] = type;
            std::cout << "Successfully added var \"" << varName << "\" connecting to the path " << path << " with method " << type << std::endl;
        }else{
            std::cout << "Error while aptempting to create var \"" << varName << "\", type must be exec or cd" << std::endl;
        }
    }else{
        std::cout << "Error while aptempting to create a new var: not enough parameters.\nSyntax is: define varname path type [cd, exec]" << std::endl;
    }
}

void ConsoleHub::load(std::string const& str){

}

void ConsoleHub::listenInputs(){
    std::string input;
    std::cout << "> ";
    while(getline(std::cin, input)){
        std::vector<std::string> args (Utils::split(input, ' '));
            if(args[0] == "define"){
                defineNew(input);
            }else if(args[0] == "exit"){
                exit(0);
            }else{
                std::cout << "Error: unknown command please type help to see the list of commands" << std::endl;
            }

        std::cout << "> ";
    }

}
