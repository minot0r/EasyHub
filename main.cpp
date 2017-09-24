#include <iostream>
#include <string>
#include <vector>

#include "Hub.h"
#include "Parser.h"
#include "Utils.h"


int main(){

    ConsoleHub hub;
    hub.affMsg();

    std::string input;

    while(getline(std::cin, input)){
        std::vector<std::string> args (Utils::split(input, ' '));
        if(args[0] == "define"){
            std::cout << Parser::getPath(input) << std::endl << Parser::getType(input) << std::endl << Parser::getVarName(input) << std::endl;
        }
    }

    return 0;
}
