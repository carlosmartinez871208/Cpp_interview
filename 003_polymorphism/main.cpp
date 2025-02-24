#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

/* Compile type polymorphism: function overloaded. */
class fOverload
{
    public:
        void func(int x){std::cout << "Value of x is: "<< x << std::endl;}
        void func(double x){std::cout << "Value of x is: "<< x << std::endl;}
        void func(int x, int y){std::cout << "Value of x is: "<< x << ", value of y is:" << y <<std::endl;}
};

/* Compile type polymorphism: operand overloaded. */
class complexNum
{
    private:
        int real, imag;
    public:
        complexNum(int r=0, int i=0)
        {
            real = r;
            imag = i;
        }
        complexNum operator+(complexNum const& obj) /* This is call when + is used between two complex objects  */
        {
            complexNum res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
        }
        void print(){std::cout << real << "+" << imag << "i" << std::endl;}
};

/* Runtime type polymorphism: function overriding with date members. */
class sports
{
    public:
        int members = 11;
};

class voleiball : public sports
{
    public:
        int members = 5;
};

/* Runtime type polymorphism: virtual function. */
class Base
{
    public:
        virtual void display(){std::cout << "Base class virtual function: called." << std::endl;}
        void print(){std::cout << "Base class print function: called." << std::endl;}
};

class Derived : public Base
{
    public:
        void display(){std::cout << "Derived class display function: called." << std::endl;}
        void print(){std::cout << "Derived class print function: called." << std::endl;}
};

int main (int argc, char** argv)
{
    fOverload CPPoly;
    std::cout << "Compile-time polymorphism: function overload." << std::endl;
    CPPoly.func(10);
    CPPoly.func(7.93);
    CPPoly.func(10,15);
    std::cout << "Compile-time polymorphism: operator overload." << std::endl;
    complexNum Num1(5,3), Num2(4,7);
    complexNum Num3 = Num1 + Num2;
    Num3.print();
    std::cout << "Runtime polymorphism: function overriding with data members." << std::endl;
    sports football = voleiball();
    std::cout << football.members << std::endl;
    std::cout << "Runtime polymorphism: virtual function." << std::endl;
    Base* master;
    Derived slave;
    master = &slave;
    master->display();
    master->print();
    return EXIT_SUCCESS;
}