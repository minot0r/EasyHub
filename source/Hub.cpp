#include "../includes/Hub.h"
#include "../includes/Utils.h"
#include "../includes/Parser.h"
#include "../includes/Printer.h"
#include "../includes/Var.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

void ConsoleHub::affMsg(){

<<<<<<< HEAD
    std::cout << "SimplHub (C++) win v" VERSION << std::endl << std::endl << "type help to start." << std::endl;
=======
    std::string display = "Easy Hub (C++) win v" VERSION;

    std::cout << display << std::endl;

    affHelp();
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c

}

void ConsoleHub::listenInputs(){
    std::string input;
    while(getWithPrefix(input)){
        onCommand(Utils::split(input, ' '), input);
    }
}

void ConsoleHub::tryLoadConfig(std::string const& path){
    std::string content;
<<<<<<< HEAD
    if(!Utils::readFile(path, content)) return;
    load(content);
    content.clear();
=======
    if(Utils::readFile(path, content)){
        load(content);
    }
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
}

void ConsoleHub::defineNew(std::string args){
    if(!Utils::contains(args, "\"")){
<<<<<<< HEAD
        if(!Utils::hasEnoughParams(Utils::split(args, ' '), 4)) return;

=======

        std::vector<std::string> eachArgs (Utils::split(args, ' '));

        if(!Utils::hasEnoughParams(eachArgs, 4)) return;
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
        define(Parser::getVarName(args), Parser::getPath(args), Parser::getType(args));
        Printer::successCreated(Parser::getVarName(args), Parser::getPath(args), Parser::getType(args));
    }else{

        std::vector<std::string> eachArgs = Utils::split(Parser::subtractBrackPath(args), ' ');
        Utils::insertAt(eachArgs, 2, Parser::getBrackPath(args));

        if(!Utils::hasEnoughParams(eachArgs, 4)) return;
<<<<<<< HEAD

=======
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
        define(eachArgs[1], eachArgs[2], eachArgs[3]);
        Printer::successCreated(eachArgs[1], eachArgs[2], eachArgs[3]);
    }
}

void ConsoleHub::exec(std::string const& str){
    std::vector<std::string> eachArgs = Utils::split(str, ' ');
    if(!Utils::hasEnoughParams(eachArgs, 2)) return;
<<<<<<< HEAD
    if(!vExists(eachArgs[1])) { Printer::doesNotExists(eachArgs[1]); return; }

    if(getVType(eachArgs[1]) == TYPE_CD){
=======
    if(!vExists(eachArgs[1])) return;
    if(getVType(eachArgs[1]) == "cd"){
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
        std::string path("start cmd /K \"cd /d ");
        path.append(getVPath(eachArgs[1]));
        path.append("\"");
        system(path.c_str());
    }else{
        std::string path("start cmd /K \"");
        path.append(getVPath(eachArgs[1]));
        path.append("\"");
        system(path.c_str());
    }
}

void ConsoleHub::onCommand(std::vector<std::string> const& args, std::string const& input){
    if(args[0] == CMD_DEFINE) defineNew(input);
    else if(args[0] == CMD_EXIT) exit(0);
    else if(args[0] ==  CMD_EXECUTE) exec(input);
    else if(args[0] == CMD_DELETE) deleteCmd(input);
    else if(args[0] == CMD_LOAD) loadFile(input);
    else if(args[0] == CMD_SAVE) saveInFile(input);
    else if(args[0] == CMD_HELP) affHelp();
    else if(args[0] == CMD_LS) ls();
    else if(args[0] == CMD_ENV) env(input);
    else if(args[0] == CMD_CMD) system("start");
<<<<<<< HEAD
    else if(args[0] == CMD_CLS) system("cls");
=======
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
    else Printer::unknwCmd(args[0]);
}

void ConsoleHub::deleteCmd(std::string const& str){
    std::vector<std::string> eachArgs = Utils::split(str, ' ');
<<<<<<< HEAD
    if(!Utils::hasEnoughParams(eachArgs, 2)) return;

=======
    if(Utils::hasEnoughParams(eachArgs, 2)) return;
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
    std::string varName = eachArgs[1];
    if(vExists(varName)){
        definedVars.erase(definedVars.begin() + getVar(varName));
        Printer::deleteVar(varName);
<<<<<<< HEAD
        return;
    }
    Printer::doesNotExists(varName);

}

void ConsoleHub::saveInFile(std::string const& str){
    std::string path;
    std::vector<std::string> eachArgs;
    if(Utils::split(str, ' ').size() == 1){ Printer::printParamsError(1, 2); return; }

    if(!Utils::contains(str, "\"")){
        eachArgs = Utils::split(str, ' ');
        path = eachArgs[1];
    }else{
        path = Parser::getBrackPath(str);
        eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        Utils::insertAt(eachArgs, 1, path);
    }

    if(!Utils::hasEnoughParams(eachArgs, 2)) return;

    if(Utils::saveFile(path, definedVars, envVars)){
        Printer::savedFile(path);
        return;
    }
    Printer::couldNotLoadFile();
}

void ConsoleHub::loadFile(std::string const& str){
    std::string path;
    std::vector<std::string> eachArgs;
    std::string content;

    if(Utils::split(str, ' ').size() == 1) { Printer::printParamsError(1, 2); return; }

    if(!Utils::contains(str, "\"")){
        eachArgs = Utils::split(str, ' ');
        path = eachArgs[1];
    }else{
        path = Parser::getBrackPath(str);
        eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        Utils::insertAt(eachArgs, 1, path);
    }

    if(!Utils::hasEnoughParams(eachArgs, 2)) return;

    if(Utils::readFile(path, content)){
        load(content);
        return;
    }

    Printer::couldNotLoadFile();
}

void ConsoleHub::affHelp(){
    std::map<std::string, std::string> cmdsHelp = ConsoleHub::init_map();
    std::cout << Printer::printHelp(cmdsHelp) << "NB: More documentation at https://github.com/minot0r/EasyHub/blob/master/README.md" << std::endl;
=======
    }else{
        Printer::doesNotExists(varName);
    }
}

void ConsoleHub::saveInFile(std::string const& str){
    if(!Utils::contains(str, "\"")){
        std::vector<std::string> eachArgs = Utils::split(str, ' ');
        if(!Utils::hasEnoughParams(eachArgs, 2)) return;
        std::string content;
        std::string path(eachArgs[1].begin(), eachArgs[1].end());
        if(Utils::saveFile(path, definedVars, envVars)){
            Printer::savedFile(path);
        }else{
            Printer::couldNotLoadFile();
        }
    }else{
        std::string path(Parser::getBrackPath(str));
        std::vector<std::string> eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        Utils::insertAt(eachArgs, 1, path);

        if(!Utils::hasEnoughParams(eachArgs, 2)) return;
        std::string content;
        if(Utils::saveFile(path, definedVars, envVars)){
            Printer::savedFile(path);
        }else{
            Printer::couldNotSaveFile();
        }
    }
}

void ConsoleHub::loadFile(std::string const& str){
    if(!Utils::contains(str, "\"")){
        std::vector<std::string> eachArgs = Utils::split(str, ' ');
        if(!Utils::hasEnoughParams(eachArgs, 2)) return;
        std::string content;
        std::string path(eachArgs[1].begin(), eachArgs[1].end());
        if(Utils::readFile(path, content)){
            load(content);
        }else{
            Printer::couldNotLoadFile();
        }
    }else{
        std::string path(Parser::getBrackPath(str));
        std::vector<std::string> eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        Utils::insertAt(eachArgs, 1, path);

        if(!Utils::hasEnoughParams(eachArgs, 2)) return;
        std::string content;
        if(Utils::readFile(path, content)){
            load(content);
        }else{
            Printer::couldNotLoadFile();
        }
    }
}

void ConsoleHub::affHelp(){
    std::string help = "\n | define a new var to the hub with: define varname path type [cd, exec]\n"
        " | execute a created var with: exc varname\n"
        " | delete a var with: delete varname\n"
        " | load a file with: load path\n"
        " | save a file with: save path\n"
        " | list your vars with: ls\n"
        " | add environment vars with: env add name path [path, none]\n"
        " | remove environment vars with: env remove name\n"
        " | start a command line with: cmd\n"
        " | note that if the path contains spaces you can add quotes\n\n";

    std::cout << help << std::endl;
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
}

void ConsoleHub::ls(){
    for(int i(0); i < definedVars.size(); i++){
<<<<<<< HEAD
        std::cout << " + Var: \"" << definedVars[i].getName() << "\" connecting to path " << definedVars[i].getPath() << " with method " << definedVars[i].getType() << std::endl;
    }
    for(int i (0); i < envVars.size(); i++){
        std::cout << " + Environment-var: \"" << envVars[i].getName() << "\" with path " << envVars[i].getPath() << ". (" << envVars[i].getLevel() << ")" << std::endl;
=======
        std::cout << std::endl << " + Var: \"" << definedVars[i].getName() << "\" connecting to path " << definedVars[i].getPath() << " with method " << definedVars[i].getType() << std::endl;
    }
    for(int i (0); i < envVars.size(); i++){
        std::cout << std::endl << " + Environment-var: \"" << envVars[i].getName() << "\" with path " << envVars[i].getPath() << ". (" << envVars[i].getLevel() << ")" << std::endl;
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
    }
}

void ConsoleHub::env(std::string const& str){
<<<<<<< HEAD

    std::vector<std::string> eachArgs;

    if(!Utils::contains(str, "\"")){
        eachArgs = Utils::split(str, ' ');
    }else{
        eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        std::string path = Parser::getBrackPath(str);
        Utils::insertAt(eachArgs, 3, path);
    }

    if(eachArgs.size() < 3) { Printer::printParamsError(eachArgs.size(), 0); return; }

    if(eachArgs.size() == 5 && eachArgs[1] == "add"){
        if(!(eachArgs[4] == LEVEL_PATH || eachArgs[4] == LEVEL_NONE)) return;
        if(!addToEnv(eachArgs[2], eachArgs[3], eachArgs[4])) return;

        Printer::successEnvCreated(eachArgs[2], eachArgs[3], eachArgs[4]);
    }else if(eachArgs.size() == 3 && eachArgs[1] == "remove"){
        if(envContains(eachArgs[2])){
            if(envVars[getEnvVar(eachArgs[2])].getLevel() == LEVEL_PATH){
                Printer::successRemoved(eachArgs[2], LEVEL_PATH);
            }else{
                std::string var(eachArgs[2] + "=");
                putenv(var.c_str());
                Printer::successRemoved(eachArgs[2], LEVEL_NONE);
            }
            envVars.erase(envVars.begin() + getEnvVar(eachArgs[2]));
            return;
        }
      Printer::notFound(eachArgs[2]);
  }else{
    Printer::unknwSubCmd(eachArgs[1]);
  }
=======
    std::vector<std::string> eachArgs = Utils::split(str, ' ');
    if(!Utils::contains(str, "\"")){
        if(eachArgs.size() == 5){
            if(eachArgs[4] == LEVEL_PATH || eachArgs[4] == LEVEL_NONE){
                if(eachArgs[1] == "add"){
                    if(addToEnv(eachArgs[2], eachArgs[3], eachArgs[4])){
                        Printer::successEnvCreated(eachArgs[2], eachArgs[3], eachArgs[4]);
                    }
                }else{
                    Printer::unknwSubCmd(eachArgs[1]);
                }
            }
        }else if(eachArgs.size() == 3){
            if(envContains(eachArgs[2])){
                if(envVars[getEnvVar(eachArgs[2])].getLevel() == LEVEL_PATH){
                    Printer::successRemoved(eachArgs[2], LEVEL_PATH);
                }else{
                    std::string var(eachArgs[2] + "=");
                    putenv(var.c_str());
                    Printer::successRemoved(eachArgs[2], LEVEL_NONE);
                }
                envVars.erase(envVars.begin() + getEnvVar(eachArgs[2]));
            }else{
                Printer::notFound(eachArgs[2]);
            }
        }else{
            Printer::printParamsError(eachArgs.size(), 0);
        }
    }else{
        std::string path(Parser::getBrackPath(str));
        eachArgs = Utils::split(Parser::subtractBrackPath(str), ' ');
        Utils::insertAt(eachArgs, 3, path);
        if(Utils::hasEnoughParams(eachArgs, 5)){
            if(eachArgs[1] == "add"){
                if(addToEnv(eachArgs[2], path, eachArgs[4])){
                    Printer::successEnvCreated(eachArgs[2], eachArgs[3], eachArgs[4]);
                }
            }else{
                Printer::unknwSubCmd(eachArgs[1]);
            }
        }
    }
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
}

bool ConsoleHub::addToEnv(std::string const& str, std::string const& path, std::string const& level){
    EnvVar var(str, path, level);
    if(level == LEVEL_PATH){
        std::string toEnv("PATH=");
        toEnv.append(getenv("PATH"));
        toEnv.append(";" + path + ";");
<<<<<<< HEAD
        putenv(toEnv.c_str());
=======
        _putenv(toEnv.c_str());
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
        if(!envContains(str)) envVars.push_back(var);
        else{
            envVars.erase(envVars.begin() + getEnvVar(var.getName()));
            envVars.push_back(var);
        }
        return true;
    }else if(level == LEVEL_NONE){
            std::string toEnv(str + "=" + path);
<<<<<<< HEAD
            putenv(toEnv.c_str());
=======
            _putenv(toEnv.c_str());
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
            envVars.push_back(var);
            if(!envContains(str)) envVars.push_back(var);
            else{
                envVars.erase(envVars.begin() + getEnvVar(var.getName()));
                envVars.push_back(var);
            }
            return true;
    }else{
        return false;
    }
}

void ConsoleHub::define(std::string const& varName, std::string const& path, std::string const& type){
<<<<<<< HEAD
    if(!(type == TYPE_CD || type == TYPE_EXEC)) return;

    Var var(varName, path, type);
    if(vExists(varName)){
        definedVars.erase(definedVars.begin() + getVar(varName));
        definedVars.push_back(var);
    }else{
        definedVars.push_back(var);
    }
    return;

    Printer::typeError(type, varName);
=======
    if(type == TYPE_CD || type == TYPE_EXEC){
        Var var(varName, path, type);
        if(vExists(varName)){
            definedVars.erase(definedVars.begin() + getVar(varName));
            definedVars.push_back(var);
        }else{
            definedVars.push_back(var);
        }
    }else{
        Printer::typeError(type, varName);
    }
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
}

bool ConsoleHub::getWithPrefix(std::string& input){
    std::cout << "$ ";
    getline(std::cin, input);
    return true;
}

void ConsoleHub::load(std::string const& str){
    std::vector<std::string> eachLine = Utils::split(str, '\n');
    for(int i(0); i < eachLine.size(); i++){
        std::vector<std::string> eachParams = Utils::split(eachLine[i], '|');
<<<<<<< HEAD
        if(!eachParams.size() == 4) return;

        Printer::fetchEnv(eachParams[1], eachParams[2], eachParams[3]);

        if(eachParams[0] == VAR_SIGN){
            define(eachParams[1], eachParams[2], eachParams[3]);
        }else if(eachParams[0] == ENVVAR_SIGN){
            addToEnv(eachParams[1], eachParams[2], eachParams[3]);
=======
        if(eachParams.size() == 4){
            if(eachParams[0] == VAR_SIGN){
                define(eachParams[1], eachParams[2], eachParams[3]);
                Printer::fetchVar(eachParams[1], eachParams[2], eachParams[3]);
            }else if(eachParams[0] == ENVVAR_SIGN){
                addToEnv(eachParams[1], eachParams[2], eachParams[3]);
                Printer::fetchEnv(eachParams[1], eachParams[2], eachParams[3]);
            }
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
        }
    }
}

bool ConsoleHub::vExists(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var){
            return true;
        }
    }
    return false;
}

std::string ConsoleHub::getVPath(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var) return definedVars[i].getPath();
    }
}

std::string ConsoleHub::getVType(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var) return definedVars[i].getType();
    }
}

int ConsoleHub::getVar(std::string const& var){
    for(int i(0); i < definedVars.size(); i++){
        if(definedVars[i].getName() == var) return i;
    }
}

bool ConsoleHub::envContains(std::string const& var){
    for(int i(0); i < envVars.size(); i++){
        if(envVars[i].getName() == var){
            return true;
        }
    }
    return false;
}

int ConsoleHub::getEnvVar(std::string const& var){
    for(int i(0); i < envVars.size(); i++){
        if(envVars[i].getName() == var) return i;
    }
}
<<<<<<< HEAD

std::map<std::string, std::string> ConsoleHub::init_map(){
    std::map<std::string, std::string> m;
    m["define"] = "Create a new variable linked to a path or an executable, syntax: define my_var \"C:/My/Path\" [cd, exec]";
    m["ex"] = "Execute a variable, syntax: ex my_var";
    m["delete"] = "Delete a variable, syntax: delete my_var";
    m["save"] = "Save a file with your variables, syntax: save C:/My/Path/config_file.ezh";
    m["load"] = "Load a file with your variables, syntax: load C:/My/Path/config_file.ezh";
    m["ls"] = "List all your variables";
    m["env"] = "Create/Delete a environment variable, syntaxes: env add my_var C:/My/Path [path, none] | env remove my_var";
    m["cmd"] = "Open a command-line";
    m["cls"] = "Clear the console";

    return m;
}
=======
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
