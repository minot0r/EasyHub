#ifndef HUB_H_INCLUDED
#define HUB_H_INCLUDED

#include <string>
#include <map>
#include <vector>

class ConsoleHub{

    public :
        void affMsg();
        void listenInputs();
        void defineNew(std::string args);
        void load(std::string const& str);

    private:
        std::map<std::string, std::map<std::string, std::string> > definedVars;
        void define(std::vector<std::string> const& eachArgs, std::string const& args);
};

#endif // HUB_H_INCLUDED
