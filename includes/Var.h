#ifndef VAR_H_INCLUDED
#define VAR_H_INCLUDED

#include <string>
#include <vector>

class Var{

    public:
        std::string getName() const;
        std::string getPath() const;
        std::string getType() const;
        std::vector<std::string> getPathes() const;
        Var(std::string varName, std::string path, std::string type);

    private:
        std::string name, path, type;
        std::vector<std::string> pathes;
};


#endif // VAR_H_INCLUDED
