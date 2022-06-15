#include "log.h"
void log(std::string& str)
{
    std::cout << str << std::endl; 
}
void log(std::string&& str)
{
    std::cout << str << std::endl; 
}