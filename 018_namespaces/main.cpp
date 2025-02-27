#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

namespace first_space
{
    void func()
    {
        std::cout << "Inside first space" << std::endl;
    }
}

namespace second_space
{
    void func()
    {
        std::cout << "Inside second space" << std::endl;
    }
}

using namespace first_space;

int main (int argc, char** argv)
{
    func();
    return EXIT_SUCCESS;
}
