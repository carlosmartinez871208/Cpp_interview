#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

static int count = 0;

class Test
{
    public:
        Test()
        {
            count++;
            std::cout << "Object created: " << count << std::endl;
        }

        ~Test()
        {
            std::cout << "Object destroyed: " << count << std::endl;
            count--;
        }
};

int main (int argc, char** argv)
{
    Test t, t1, t2, t3;
    return EXIT_SUCCESS;
}