//ex3-1.hpp
#include <string>

const int SIZE = 5;

struct Point3D
{
    int x;
    int y;
    int z;
};

struct DiffVariables
{
    int integer;
    double floatingPoint;
    char character;
    bool boolean;
    std::string str;
    char charArray[SIZE];
    int intArray[SIZE];
    double floatArray[SIZE];
    bool boolArray[SIZE];
    std::string strArray[SIZE];
};
