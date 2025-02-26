#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif


int main (int argc, char** argv)
{
    int x = -1;
    std::cout << "Before try" << std::endl;
    try
    {
        std::cout << "Inside try" << std::endl;
        if(x<0){
            throw x;
            std::cout << "After throw (Never executed)" << std::endl;
        }
    }
    catch(int x)
    {
        std::cout << "Exception caught" << std::endl;
    }
    return EXIT_SUCCESS;
}
