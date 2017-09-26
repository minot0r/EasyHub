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
    for(int i(0); i < len; i++){
        if(chars[i] == splitter){
            if(!(i == len-1 && chars[i] != splitter)){
                if(chars[i+1] != splitter){
                    fin.push_back(temp.substr(last, i-last));
                    last = i + 1;
                }else{
                    last = i + 1;
                }
            }else{
                fin.push_back(temp.substr(last, i-last));
            }
        }
    }

    delete chars;
    return fin;
}

int Utils::getFirst(std::string const& str, char const& first){
    char const* chars = str.c_str();

    for(int i(0); i < str.length(); i++){
        if(chars[i] == first){
            delete chars;
            return i;
        }
    }
}

int Utils::getLast(std::string const& str, char const& last){
    char const* chars = str.c_str();
    int fin(0);

    for(int i(0); i < str.length(); i++){
        if(chars[i] == last){
            fin = i;
        }
    }

    delete chars;
    return fin;
}
