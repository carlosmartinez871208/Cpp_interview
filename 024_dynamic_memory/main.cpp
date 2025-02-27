#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class Box
{
    public:
        Box()
        {
            std::cout << "Constructor called!" <<std::endl;
        }

        ~Box()
        {
            std::cout << "Destructor called!" <<std::endl;
        }
};

int main (int argc, char** argv)
{
    double* pvalue = nullptr;
    pvalue = new double;
    *pvalue = 3.14259;
    std::cout << "Value of pvalue: " << *pvalue << std::endl;
    Box* myBoxArray = new Box[4];
    delete[] myBoxArray;
    delete pvalue;
    return EXIT_SUCCESS;
}
