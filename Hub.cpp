#include "Hub.h"
#include "Utils.h"
#include "Parser.h"

#include <string>
#include <iostream>

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

    std::string help = "define a new var to the hub with: define varname path type [cd, exec]\n"
    "load a created var with load varname\n"
    "finally delete a var with delete varname";

    std::cout << display << std::endl << help << std::endl;


}

void ConsoleHub::defineNew(std::string const& args){
//    ConsoleHub::definedVars[Parser.getVarName(args)][Parser.getPath(args)] = Parser.getType(args);
}

void ConsoleHub::load(std::string const& str){

}
