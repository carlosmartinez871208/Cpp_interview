#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

namespace myspace
{
    class myclass
    {
        public:
            void display()
            {
                std::cout << "Displaying: myspace::myclass::display()" << std::endl;
            }
    };
}

/*****************************************************************************************************/
namespace myspace2
{
    class myclass;
}

class myspace2::myclass
{
    public:
        void display() {std::cout << "Displaying: myspace2::myclass::display()" << std::endl;}
};
/*******************************************************************************************************/
namespace myspace3
{
    void display();
    class myclass
    {
        public:
            void display();
    };
}

void myspace3::myclass::display()
{
    std::cout << "Displaying: myspace3::myclass::display()" << std::endl;
}

void myspace3::display() {std::cout << "Displaying: myspace3::display()" << std::endl;;}

int main (int argc, char** argv)
{
    myspace::myclass obj;
    obj.display();
    myspace2::myclass obj2;
    obj2.display();
    myspace3::myclass obj3;
    myspace3::display();
    obj3.display();
    return EXIT_SUCCESS;
}
