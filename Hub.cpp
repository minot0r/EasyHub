#include "Hub.h"
#include "Utils.h"
#include "Parser.h"
#include "Printer.h"

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

void ConsoleHub::define(std::string const& varName, std::string const& path, std::string const& type){
    if(type == "cd" || type == "exec"){
        ConsoleHub::definedVars[varName][path] = type;
        Printer::successCreated(varName, path, type);
    }else{
        Printer::typeError(type, varName);
    }
}

void ConsoleHub::defineNew(std::string args){
    if(!Utils::contains(args, "\"")){

        std::vector<std::string> eachArgs (Utils::split(args, ' '));

        if(Utils::hasEnoughParams(eachArgs, 4)){
            define(Parser::getVarName(args), Parser::getPath(args), Parser::getType(args));
        }else{
            Printer::printParamsError(eachArgs.size());
        }
    }else{

        std::vector<std::string> eachArgs = Utils::split(Parser::subtractBrackPath(args), ' ');
        Utils::insertAt(eachArgs, 2, Parser::getBrackPath(args));

        if(Utils::hasEnoughParams(eachArgs, 4)){
            define(eachArgs[1], eachArgs[2], eachArgs[3]);
        }else{
            Printer::printParamsError(eachArgs.size());
        }
    }
}

void ConsoleHub::load(std::string const& str){

}

void ConsoleHub::listenInputs(){
    std::string input;
    while(getWithPrefix(input)){
        onCommand(Utils::split(input, ' '), input);
    }

}

void ConsoleHub::onCommand(std::vector<std::string> const& args, std::string const& input){
    if(args[0] == "define"){
        defineNew(input);
    }else if(args[0] == "exit"){
        exit(0);
    }else{
        Printer::unknwCmd(args[0]);
    }
}

bool ConsoleHub::getWithPrefix(std::string& input){
    std::cout << "$ ";
    getline(std::cin, input);
    return true;
}
