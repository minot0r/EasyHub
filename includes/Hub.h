#ifndef HUB_H_INCLUDED
#define HUB_H_INCLUDED

#include "Var.h"
#include "EnvVar.h"

#include <string>
#include <map>
#include <vector>

#define LEVEL_OVERRIDE "override"
#define LEVEL_NONE "none"

#define TYPE_CD "cd"
#define TYPE_EXEC "exec"

#define VAR_SIGN "&"
#define ENVVAR_SIGN "$"

#define CMD_HELP "help"
#define CMD_LS "ls"
#define CMD_ENV "env"
#define CMD_DEFINE "define"
#define CMD_DELETE "delete"
#define CMD_EXIT "exit"
#define CMD_EXECUTE "exc"
#define CMD_LOAD "load"
#define CMD_SAVE "save"
#define CMD_CMD "cmd"

#define VERSION "2.6"

class ConsoleHub{

    public : // These are the methods called by Main.cpp
        void affMsg();
        void listenInputs();
        void tryLoadConfig(std::string const& path);

    private:

        // List of variables

        std::vector<Var> definedVars;
        std::vector<EnvVar> envVars;

        // Commands methods

        void defineNew(std::string args);
        void exec(std::string const& str);
        void onCommand(std::vector<std::string> const& args, std::string const& input);
        void deleteCmd(std::string const& str);
        void saveInFile(std::string const& str);
        void loadFile(std::string const& str);
        void affHelp();
        void ls();
        void env(std::string const& str);

        // Sub-commands methods

        bool addToEnv(std::string const& str, std::string const& path, std::string const& level);
        void define(std::string const& varName, std::string const& path, std::string const& type);
        bool getWithPrefix(std::string& input);
        void load(std::string const& str);

        // Var Methods

        bool vExists(std::string const& var);
        std::string getVPath(std::string const& var);
        std::string getVType(std::string const& var);
        int getVar(std::string const& var);

        // EnvVar Methods

        bool envContains(std::string const& var);
        int getEnvVar(std::string const& var);

};

#endif // HUB_H_INCLUDED
