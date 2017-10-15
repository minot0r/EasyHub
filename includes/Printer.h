#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

#include <string>
#include <vector>
#include <map>

class Printer{

    public:
        static void printParamsError(int const& paramsLen, int const& needed);
        static void successCreated(std::string const& var, std::string const& path, std::string const& type);
        static void successEnvCreated(std::string const& var, std::string const& path, std::string const& level);
        static void typeError(std::string const& type, std::string const& var);
        static void unknwCmd(std::string const& cmd);
        static void unknwSubCmd(std::string const& scmd);
        static void deleteVar(std::string const& var);
        static void doesNotExists(std::string const& var);
        static void couldNotLoadFile();
        static void couldNotSaveFile();
        static void fetchVar(std::string const& var, std::string const& path, std::string const& type);
        static void fetchEnv(std::string const& var, std::string const& path, std::string const& type);
        static void savedFile(std::string const& path);
        static void notFound(std::string const& var);
        static void successRemoved(std::string const& var, std::string const& level);
        static void printEnvError();
        static std::string printHelp(std::map<std::string, std::string> help);

};


#endif // PRINTER_H_INCLUDED
