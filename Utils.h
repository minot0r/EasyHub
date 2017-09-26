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
        static int getLast(std::string const& str, char const& last);
        static int getFirst(std::string const& str, char const& first);
        static void insertAt(std::vector<std::string>& vec, int const& index, std::string const& value);
};

#endif // UTILS_H_INCLUDED
