#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

#include <string>
#include <vector>
<<<<<<< HEAD
#include <map>
=======
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c

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
<<<<<<< HEAD
        static std::string printHelp(std::map<std::string, std::string> help);
=======
>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c

};


#endif // PRINTER_H_INCLUDED
