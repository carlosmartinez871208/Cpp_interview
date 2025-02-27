#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

void pointers ()
{
    int var = 20;
    int* ptr;
    ptr = &var;
    std::cout << "Value at var: " << var << std::endl;
    std::cout << "Address of var stored at ptr: " << ptr << std::endl;
    std::cout << "Address of ptr (pointer variable address): " << &ptr << std::endl;
    std::cout << "Value at *prt (dereference): " << *ptr << std::endl;
}

int main (int argc, char** argv)
{
    pointers();
    return EXIT_SUCCESS;
}
