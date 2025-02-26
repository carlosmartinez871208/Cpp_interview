#include <iostream>
#include <stdexcept>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif


int main (int argc, char** argv)
{
    try
    {
        int numerator=10;
        int denominator=0;
        int res;
        if(0 == denominator)
        {
            throw std::runtime_error("Division by zero not allowed");
        }
        else
        {
            res  = numerator/denominator;
            std::cout << "Result: " << res <<std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return EXIT_SUCCESS;
}
