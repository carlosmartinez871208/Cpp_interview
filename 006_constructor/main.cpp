#include <iostream>
#include <cstdlib>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

/* Constructor within a class. */
class student
{
    int Num;
    char name[50];
    double fee;
    public:
        student()
        {
            std::cout << "Enter number: " << std::endl;
            std::cin >> Num;                                                         
            std::cout << "Enter name: " << std::endl;
            std::cin >> name;
            std::cout << "Enter the fee: " << std::endl;
            std::cin >> fee;
        }
        void display()
        {
            std::cout << Num << ", " << name << ", " << fee << std::endl;
        }
};

/* Constructor outside the class. */
class player
{
    int Num;
    char name[50];
    double fee;
    public:
        /* shall declare inside the class before defining the constructor outside the class. */
        player();
        void display();
};

player::player()
{
    std::cout << "Enter number: " << std::endl;
    std::cin >> Num;
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter the fee: " << std::endl;
    std::cin >> fee;
}

void player::display()
{
    std::cout << Num << ", " << name << ", " << fee << std::endl;
}

/* Parameterized constructor */
class gamer
{
    int Num;
    std::string name;
    double fee;
    public:
        gamer (int,std::string,double);
        void display ();
};

gamer::gamer (int no, std::string na, double f)
{
    Num = no;
    name = na;
    fee = f;
}

void gamer::display()
{
    std::cout << Num << ", " << name << ", " << fee << std::endl;
}

/* Copy constructor */
class A
{
    public:
        int x;
        A(){};
        /* Copy constructor definition. */
        A(A &t)
        {
            x = t.x;
            std::cout << "Calling copy constructor." << std::endl;
        }
};

/* Move constructor */
class Simple
{
    private:
        int* data;

    public:
        Simple (int value) : data(new int(value)) /* Cosntructor */
        {
            std::cout << "Constructor called, data = " << *data << std::endl;
        }

        ~Simple() /* Destructor */
        {
            delete data;
            std::cout << "Destructor called" << std::endl;
        }

        Simple(Simple&& other) : data(other.data) /* Move constructor */
        {
            other.data = nullptr;
            std::cout << "Move Constructor called" << std::endl;
        }

        Simple& operator=(Simple&& other)
        {
            if(this != &other)
            {
                delete data;
                data = other.data;
                other.data = nullptr;
                std::cout << "Move assignment called" << std::endl;
            }
            return *this;
        }

        Simple(const Simple&) = delete;
        Simple& operator=(const Simple&) = delete;

        void print()
        {
            if (data)
            {
                std::cout << "Data: " << *data << std::endl;
            }
            else
            {
                std::cout << "Data is null " << std::endl;
            }
        }
};

int main (int argc, char** argv)
{
    student s;
    s.display();
    player p;
    p.display();
    gamer g (2,"Mely",100);
    g.display();
    A a1;
    a1.x = 10;
    std::cout << "a1, x = " << a1.x << std::endl;
    A a2(a1);
    std::cout << "a2, x = " << a1.x << std::endl;
    Simple obj1(37);
    obj1.print();
    Simple obj2 = std::move(obj1);
    obj2.print();
    obj1.print();
    Simple obj3(84);
    obj3 = std::move(obj2);
    obj3.print();
    obj2.print();
    return EXIT_SUCCESS;
}