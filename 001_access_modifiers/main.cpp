#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class A
{
    private:
        int privateVar;

    protected:
        int protectedVar;

    public:
        int publicVar;
};

class derivedFromA: A
{
    public:
        //int fun1(){return privateVar;} /* Compilation error: is private within this context. */
        int fun2(){return protectedVar;} /* OK. */
        int fun3(){return publicVar;}    /* OK. */
};

class notRelatedWithA
{
    private:
        A B; /* Object B created from class A. */

    public:
        //int fun1(){return B.privateVar;}   /* Compilation error: is private within this context. */
        //int fun2(){return B.protectedVar;} /* Compilation error: is protected within this context. */
        int fun3(){return B.publicVar;}    /* OK. */
};

int main (int argc, char** argv)
{
    derivedFromA objectA;
    return EXIT_SUCCESS;
}