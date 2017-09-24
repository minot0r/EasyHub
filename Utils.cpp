#include "Utils.h"

#include <algorithm>
#include <string>
#include <vector>

void Utils::toLowerCase(std::string toLow){
    std::transform(toLow.begin(), toLow.end(), toLow.begin(), ::tolower);
}

bool Utils::containsAtIndex(std::string const& containsStr, std::string const& inputString, int const& index){
    if (inputString.find(containsStr) == index){
        return true;
    }else{
        return false;
    }
}

bool Utils::contains(std::string const& container, std::string const& contained){
    if (container.find(contained) != std::string::npos) {
        return true;
    }else{
        return false;
    }
}

std::vector<std::string> Utils::split(std::string const& str, char const& splitter){
    std::string temp(str + " ");
    std::vector<std::string> fin;
    int len = temp.length();
    const char* chars = temp.c_str();

    int last = 0;
    for(int iterato(0); iterato < len; iterato++){
        if(chars[iterato] == splitter || (iterato == len-1 && temp.at(iterato) != splitter)){
            fin.push_back(temp.substr(last, iterato-last));
            last = iterato + 1;
        }
    }

    return fin;
}
