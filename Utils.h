#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
#include <vector>

class Utils{

    public:
        static void toLowerCase(std::string toLow);
        static bool containsAtIndex(std::string const& containsStr, std::string const& inputString, int const& index);
        static bool contains(std::string const& container, std::string const& contained);
        static std::vector<std::string> split(std::string const& str, char const& splitter);

};

#endif // UTILS_H_INCLUDED
