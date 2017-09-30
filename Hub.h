#ifndef HUB_H_INCLUDED
#define HUB_H_INCLUDED

#include "Var.h"

#include <string>
#include <map>
#include <vector>

class ConsoleHub{

    public :
        void affMsg();
        void listenInputs();

    private:
        std::vector<Var> definedVars;
        void define(std::string const& varName, std::string const& path, std::string const& type);
        bool getWithPrefix(std::string& input);
        std::string version = "1.1";
        bool exists(std::string const& var);
        std::string getPath(std::string const& var);
        std::string getType(std::string const& var);
        int getVar(std::string const& var);
        void defineNew(std::string args);
        void exec(std::string const& str);
        void onCommand(std::vector<std::string> const& args, std::string const& input);
        void deleteCmd(std::string const& str);
        void saveInFile(std::string const& str);
        void loadFile(std::string const& str);
        void load(std::string const& str);

};

#endif // HUB_H_INCLUDED
