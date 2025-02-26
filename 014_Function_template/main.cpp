#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

template <typename T> T myMax(T x, T y)
{
    return (x>y)?x:y;
}

int main (int argc, char** argv)
{
    std::cout << myMax<int>(3,7) << std::endl;
    std::cout << myMax<double>(3.5,7.6) << std::endl;
    std::cout << myMax<char>('g','e') << std::endl;
    return EXIT_SUCCESS;
}
