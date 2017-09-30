#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

#include <string>
#include <vector>

class Printer{

    public:
        static void printParamsError(int const& paramsLen, int const& needed);
        static void successCreated(std::string const& var, std::string const& path, std::string const& type);
        static void typeError(std::string const& type, std::string const& var);
        static void unknwCmd(std::string const& cmd);
        static void deleteVar(std::string const& var);
        static void doesNotExists(std::string const& var);
        static void couldNotLoadFile();
        static void couldNotSaveFile();
        static void fetchFile(std::string const& var, std::string const& path, std::string const& type);
        static void savedFile(std::string const& path);

};


#endif // PRINTER_H_INCLUDED
