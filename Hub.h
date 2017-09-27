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
        void onCommand(std::vector<std::string> const& args, std::string const& input);

    private:
        std::map<std::string, std::map<std::string, std::string> > definedVars;
        void define(std::string const& varName, std::string const& path, std::string const& type);
};

#endif // HUB_H_INCLUDED
