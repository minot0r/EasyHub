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
        void deleteCmd(std::string const& str);

    private:
        std::map<std::string, std::string[2]> definedVars;
        void define(std::string const& varName, std::string const& path, std::string const& type);
        bool getWithPrefix(std::string& input);
        std::string version = "1.0";
        bool exists(std::string const& var);
        std::string getPath(std::string const& var);

};

#endif // HUB_H_INCLUDED
