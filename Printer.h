#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED

#include <string>
#include <vector>

class Printer{

    public:
        static void printParamsError(int const& paramsLen);
        static void successCreated(std::string const& var, std::string const& path, std::string const& type);
        static void typeError(std::string const& type, std::string const& var);
        static void unknwCmd(std::string const& cmd);
        static void deleteVar(std::string const& var);
        static void doesNotExists(std::string const& var);

};


#endif // PRINTER_H_INCLUDED
