#include "Hub.h"
#include "Utils.h"
#include "Parser.h"
#include "Printer.h"
#include "Var.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

void ConsoleHub::affMsg(){

    std::string display = "Easy Hub (C++) win v";
    display.append(version);

    std::cout << display << std::endl;

    affHelp();

}

void ConsoleHub::affHelp(){
    std::string help = "\n | define a new var to the hub with: define varname path type [cd, exec]\n"
        " | execute a created var with: exc varname\n"
        " | delete a var with: delete varname\n"
        " | load a file with: load path\n"
        " | save a file with: save path\n"
        " | list your vars with: ls\n"
        " | note that if the path contains spaces you can add quotes\n\n";

    std::cout << help << std::endl;
}

void ConsoleHub::ls(){
    for(int i(0); i < definedVars.size(); i++){
        std::cout << std::endl << " + Var: \"" << definedVars[i].getName() << "\" connecting to path " << definedVars[i].getPath() << " with method " << definedVars[i].getType() << std::endl;
    }
}

void ConsoleHub::define(std::string const& varName, std::string const& path, std::string const& type){
    if(type == "cd" || type == "exec"){
        Var var(varName, path, type);
        if(exists(varName)){
            definedVars.erase(definedVars.begin() + getVar(varName));
            definedVars.push_back(var);
        }else{
            definedVars.push_back(var);
        }
    }else{
        Printer::typeError(type, varName);
    }
}

void ConsoleHub::defineNew(std::string args){
    if(!Utils::contains(args, "\"")){

        std::vector<std::string> eachArgs (Utils::split(args, ' '));

        if(Utils::hasEnoughParams(eachArgs, 4)){
            define(Parser::getVarName(args), Parser::getPath(args), Parser::getType(args));
            Printer::successCreated(Parser::getVarName(args), Parser::getPath(args), Parser::getType(args));
        }else{
            Printer::printParamsError(eachArgs.size(), 4);
        }
    }else{

        std::vector<std::string> eachArgs = Utils::split(Parser::subtractBrackPath(args), ' ');
        Utils::insertAt(eachArgs, 2, Parser::getBrackPath(args));

        if(Utils::hasEnoughParams(eachArgs, 4)){
            define(eachArgs[1], eachArgs[2], eachArgs[3]);
            Printer::successCreated(eachArgs[1], eachArgs[2], eachArgs[3]);
        }else{
            Printer::printParamsError(eachArgs.size(), 4);
        }
    }
}

bool ConsoleHub::exists(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var){
            return true;
        }
    }
    return false;
}

std::string ConsoleHub::getPath(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var) return definedVars[i].getPath();
    }
}

std::string ConsoleHub::getType(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var) return definedVars[i].getType();
    }
}
int ConsoleHub::getVar(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var) return i;
    }
}

void ConsoleHub::exec(std::string const& str){
    std::vector<std::string> eachArgs = Utils::split(str, ' ');
    if(Utils::hasEnoughParams(eachArgs, 2)){
        if(exists(eachArgs[1])){
            if(getType(eachArgs[1]) == "cd"){
                std::string path("start cmd /K \"cd /d ");
                path.append(getPath(eachArgs[1]));
                path.append("\"");
                system(path.c_str());
            }else{
                std::string path("start cmd /K \"");
                path.append(getPath(eachArgs[1]));
                path.append("\"");
                system(path.c_str());
            }
        }
    }else{
        Printer::printParamsError(eachArgs.size(), 2);
    }
}

void ConsoleHub::listenInputs(){
    std::string input;
    while(getWithPrefix(input)){
        onCommand(Utils::split(input, ' '), input);
    }

}

void ConsoleHub::onCommand(std::vector<std::string> const& args, std::string const& input){
    if(args[0] == "define") defineNew(input);
    else if(args[0] == "exit") exit(0);
    else if(args[0] ==  "exc") exec(input);
    else if(args[0] == "delete") deleteCmd(input);
    else if(args[0] == "load") loadFile(input);
    else if(args[0] == "save") saveInFile(input);
    else if(args[0] == "help") affHelp();
    else if(args[0] == "ls") ls();
    else Printer::unknwCmd(args[0]);
}

bool ConsoleHub::getWithPrefix(std::string& input){
    std::cout << "$ ";
    getline(std::cin, input);
    return true;
}

void ConsoleHub::deleteCmd(std::string const& str){
    std::vector<std::string> eachArgs = Utils::split(str, ' ');
    if(Utils::hasEnoughParams(eachArgs, 2)){
        std::string varName = eachArgs[1];
        if(exists(varName)){
            definedVars.erase(definedVars.begin() + getVar(varName));
            Printer::deleteVar(varName);
        }else{
            Printer::doesNotExists(varName);
        }
    }else{
        Printer::printParamsError(eachArgs.size(), 2);
    }
}

void ConsoleHub::loadFile(std::string const& str){
    if(!Utils::contains(str, "\"")){
        std::vector<std::string> eachArgs = Utils::split(str, ' ');
        if(Utils::hasEnoughParams(eachArgs, 2)){
            std::string content;
            std::string path(eachArgs[1].begin(), eachArgs[1].end());
            if(Utils::readFile(path, content)){
                load(content);
            }else{
                Printer::couldNotLoadFile();
            }
        }else{
            Printer::printParamsError(eachArgs.size(), 2);
        }
    }else{
        std::string path(Parser::getBrackPath(str));
        std::vector<std::string> eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        Utils::insertAt(eachArgs, 1, path);

        if(Utils::hasEnoughParams(eachArgs, 2)){
            std::string content;
            if(Utils::readFile(path, content)){
                load(content);
            }else{
                Printer::couldNotLoadFile();
            }
        }else{
            Printer::printParamsError(eachArgs.size(), 2);
        }
    }
}

void ConsoleHub::load(std::string const& str){
    std::vector<std::string> eachLine = Utils::split(str, '\n');
    for(int i(0); i < eachLine.size(); i++){
        std::vector<std::string> eachParams = Utils::split(eachLine[i], '|');
        if(eachParams.size() >= 3){
            define(eachParams[0], eachParams[1], eachParams[2]);
            Printer::fetchFile(eachParams[0], eachParams[1], eachParams[2]);
        }else{

        }
    }
}

void ConsoleHub::saveInFile(std::string const& str){
    if(!Utils::contains(str, "\"")){
        std::vector<std::string> eachArgs = Utils::split(str, ' ');
        if(Utils::hasEnoughParams(eachArgs, 2)){
            std::string content;
            std::string path(eachArgs[1].begin(), eachArgs[1].end());
            if(Utils::saveFile(path, definedVars)){
                Printer::savedFile(path);
            }else{
                Printer::couldNotLoadFile();
            }
        }else{
            Printer::printParamsError(eachArgs.size(), 2);
        }
    }else{
        std::string path(Parser::getBrackPath(str));
        std::vector<std::string> eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        Utils::insertAt(eachArgs, 1, path);

        if(Utils::hasEnoughParams(eachArgs, 2)){
            std::string content;
            if(Utils::saveFile(path, definedVars)){
                Printer::savedFile(path);
            }else{
                Printer::couldNotSaveFile();
            }
        }else{
            Printer::printParamsError(eachArgs.size(), 2);
        }
    }
}
