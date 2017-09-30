#ifndef VAR_H_INCLUDED
#define VAR_H_INCLUDED

#include <string>

class Var{

    public:
        std::string getName() const;
        std::string getPath() const;
        std::string getType() const;
        Var(std::string varName, std::string path, std::string type);

    private:
        std::string name, path, type;
};


#endif // VAR_H_INCLUDED
