#include "Utils.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

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

void Utils::removeBlank(std::vector<std::string> &vec){
    for(int i(0); i < vec.size(); i++){
        if(vec[i] == ""){
            vec.erase(vec.begin()+i);
        }
    }
}

std::vector<std::string> Utils::split(std::string const& str, char const& splitter){
    std::string temp(str + " ");
    std::vector<std::string> fin;
    int len = temp.length();
    const char* chars = temp.c_str();

    int last = 0;
    for(int i(0); i < len; i++){
        if(chars[i] == splitter || (i == len-1 && chars[i] != splitter)){
            fin.push_back(temp.substr(last, i-last));
            last = i + 1;
        }
    }

    Utils::removeBlank(fin);

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

void Utils::insertAt(std::vector<std::string>& vec, int const& index, std::string const& value){
    std::vector<std::string>::iterator it;
    it = vec.begin();
    it = vec.insert (it + index, value);
}
