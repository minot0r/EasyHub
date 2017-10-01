#ifndef ENVVAR_H_INCLUDED
#define ENVVAR_H_INCLUDED

#include <string>
#include <vector>

class EnvVar{

    public:
        std::string getName() const;
        std::string getPath() const;
        std::string getLevel() const;
        EnvVar(std::string varName, std::string path, std::string level);

    private:
        std::string name, path, level;
};


#endif // ENVVAR_H_INCLUDED
