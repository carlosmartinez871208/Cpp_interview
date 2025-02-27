#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif


/* Pass by value */
int pass_by_value (int n)
{
    std::cout << "Address of n(n1) in pass_by_value function: " << &n << std::endl;
    n *= n;
    return n;
}

/* Pass by reference with pointer arguments */
void pass_by_reference_ptrArg (int* n)
{
    std::cout << "Address of n(n2) in pass_by_reference_ptrArg function: " << n << std::endl;
    *n *= *n;
}

/* Pass by reference with reference arguments */
void pass_by_reference_refArg (int& n)
{
    std::cout << "Address of n(n3) in pass_by_reference_refArg function: " << &n << std::endl;
    n *= n;
}

int main (int argc, char** argv)
{
    /* Call by value */
    int n1 = 8;
    std::cout << "Address of n1 in main(): " << &n1 << std::endl;
    std::cout << "Value of n1 at pass_by_value: " << pass_by_value(n1) << std::endl;
    std::cout << "No change in n1: " << n1 << std::endl;

    /* Call by reference with pointer arguments */
    int n2 = 8;
    std::cout << "Address of n2 in main(): " << &n2 << std::endl;
    pass_by_reference_ptrArg(&n2);
    std::cout << "Value of n2 at pass_by_reference_ptrArg: " << n2 << std::endl;
    std::cout << "Change reflected in n2: " << n2 << std::endl;

    /* Call by reference with reference arguments */
    int n3 = 8;
    std::cout << "Address of n3 in main(): " << &n3 << std::endl;
    pass_by_reference_refArg(n3);
    std::cout << "Value of n3 at pass_by_reference_ptrArg: " << n3 << std::endl;
    std::cout << "Change reflected in n3: " << n3 << std::endl;
    return EXIT_SUCCESS;
}
