#ifndef HUB_H_INCLUDED
#define HUB_H_INCLUDED

#include <string>
#include <map>

class ConsoleHub{

    public :
        void affMsg();
        void defineNew(std::string const& args);
        void load(std::string const& str);

    private:
        std::map<std::string, std::map<std::string, std::string> > definedVars;
};

#endif // HUB_H_INCLUDED
