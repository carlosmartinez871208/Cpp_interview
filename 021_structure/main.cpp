#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

struct Point
{
    int x, y;
};  

int main (int argc, char** argv)
{
    struct Point arr[10];
    arr[0].x = 10;
    arr[0].y = 25;
    std::cout << arr[0].x << " " << arr[0].y << std::endl;
    return EXIT_SUCCESS;
}
