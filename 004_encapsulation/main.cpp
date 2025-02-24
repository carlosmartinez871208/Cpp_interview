#include <iostream>
#include <cstdlib>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

/* Example1 */
class example
{
    int a;
    int b;
    public:
        int solve (int input) /* Access private elements from public function. */
        {
            a=input;
            b=a/2;
            return b;
        }
};

/* Example2 */
class Person
{
    private:
        std::string name;
        int age;
    public:
        Person (std::string name, int age)
        {
            this->name = name;
            this->age = age;
        }
        void setName(std::string name)
        {
            this->name = name;
        }
        std::string getName()
        {
            return name;
        }
        void setAge(int age)
        {
            this->age = age;
        }
        int getAge ()
        {
            return age;
        }
};

/* Example 3 */
class Encapsulation
{
    private:
        /* Data hidden form outside */
        int x;
    public:
        /* Function to set variable 'x' */
        void set(int a) {x=a;}
        int get() {return x;}
};

/* Example 4 */
class Circle
{
    private:
        float area;
        float radius;
        const float PI {3.14159};
    public:
        void getRadius()
        {
            std::cout << "Enter radius: " << std::endl;
            std::cin >> radius;
        }
        void findArea()
        {
            area = PI * radius * radius;
            std::cout << "Circle area: " << area << std::endl;
        }
};

int main (int argc, char** argv)
{
    int n;
    std::cout << "Example1 of encasulation, type any value: " << std::endl;
    std::cin >> n;
    example value;
    int retVal = value.solve(n);
    std::cout << "Return value from class: " << retVal << std::endl;
    std::cout << "Example2 of encapsulation" << std::endl;
    Person person("Ninmah Martinez",5);
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Name: " << person.getAge() << std::endl;
    person.setName("Carlos Martinez");
    person.setAge(37);
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Name: " << person.getAge() << std::endl;
    std::cout << "Example3 of encapsulation" << std::endl;
    Encapsulation obj;
    obj.set(10);
    std::cout << "Value of 'x': " << obj.get() << std::endl;
    std::cout << "Example4 of encapsulation" << std::endl;
    Circle circle;
    circle.getRadius();
    circle.findArea();
    return EXIT_SUCCESS;
}