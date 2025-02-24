# Interview questions and exercises

## **1.-** What's the difference between C and C++?

| **C language**                                       | **C ++ language**                                    |
|------------------------------------------------------|------------------------------------------------------|
| Is a procedure oriented programming language.        | It's partially object oriented programming language. |
| It follows top-down approach.                        | It follows bottom-up approach.                       |
| It doesn's support function or operator overloading. | Supports function as well function overloading.      |
| It doesn't support virtual and friend functions.     | Support both virtual and friend functions.           |
| It has 32 keywords.                                  | Contains 52 keywords                                 |

## **2.-** What's a class?
A class is user-defined data type with date members and member functions and is defined with the keyword **class**.

    class className
    {
        Access specifier: /* can be public, private or protected, follow with ":". */
        Data members;     /* Variables to be used. */
        Member functions; /* Methods to access data members. */
    }; /* class ends with a semicolon ";" */

Example:

    class myClass
    {
        public:          /* Access specifier. */
            int var;     /* Data member. */
            void print() /* Methods to access data members. */
            {
                std::cout << "Hello" << std::endl;
            }
    };                   /* class ends with a semicolon ";" */

## **3.-** What's an object?
Objects are defined as an instance of a class. Once the object is created, then it can operate on both data members and member functions.

    ClassName ObjectName;

Example:

    myClass myObject;

## **4.-** Write a class example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class myClass
    {
        public:          /* Access specifier. */
            int var;     /* Data member. */
            void print() /* Methods to access data members. */
            {
                std::cout << "Hello" << std::endl;
            }
    };

    int main (int argc, char** argv)
    {
        myClass myObject;
        myObject.print();
        return EXIT_SUCCESS;
    }

## **5.-** What are access modifiers?
Access modifiers are used to define accessibility for the class members. It define how the members of a class are accessed outside the class scope.

### Private:
Members of a class **A** are not accessible outside of A's code, or from the code of any class derived from A.

### Public:
Members of a class **A** are accessible for all and everyone.

### Protected:
Members of a class **A** are not accessible outside of A's code, but is accessible from the code of any class derived from A.

Example:

    class A
    {
        private:
            int privateVar;

        protected:
            int protectedVar;

        public:
            int publicVar;
    }

    class derivedFromA : A
    {
        public:
            int fun1(){return privateVar;}    /* Compilation error: is private within this context */
            int fun2(){return protectedVar;}  /* OK */
            int fun3(){return publicVar;}     /* OK */
    }

    class notRelatedWithA
    {
        private:
            A B; /* Object B created from class A. */

        public:
            int fun1(){return B.privateVar;}   /* Compilation error: is private within this context. */
            int fun2(){return B.protectedVar;} /* Compilation error: is protected within this context. */
            int fun3(){return B.publicVar;}    /* OK. */
    };

## **6.-** What are C++ OOPs concept?
### Object.
This is the basic unit of OOP and it is an instance of a class. It can be created multiple objects from a class.

See question 3.

### Class.
It is a template of and object. It is user defined date type which holds function members and data members, inside the class.

See questions 2.

### Inheritance.
It is a process where a child class inherits all properties and behavior from the parent class.
The class that is inherit is called **base** class.
The class inherited from **base** is called **derived** class.

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    /* This is the base class */
    class base
    {
        public:
            int id_base;
            void printB(){std::cout << "Base ID: " << id_base << std::endl;}
    };

    /* This is the derived class from base: this inherits behaviors and data from base public. */
    class derived : public base
    {
        public:
            int id_derived;
            void printD(){std::cout << "Derived ID: " << id_derived << std::endl;}
    };

    int main (int argc, char** argv)
    {
        derived object; /* derived class instanciation */
        object.id_base = 2; /* Access to base class members */
        object.printB();
        object.id_derived = 4; /* Access to base class members */
        object.printD();
        return EXIT_SUCCESS;
    }

### Polymorphism.
This word means "having different forms" and this the ability of a message to be displayed in more than one form.
#### Types of polymorphism 
#### Compile-time polymorphism.
This type of polymorphism is achieved by function overloading or operator overloading.

**Function Overloading**

When there are multiple functions with the same name but different parameters.

Functions can be overloaded by changing the number of arguments or/and changing the type of arguments.

In simple terms, it is a feature of OOP providing many functions that have the same name but distint parameters when numerous tasks are listed under one function name.

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
    /***************************************************/

    int main (int argc, char** argv)
    {
        fOverload CPPoly;
        std::cout << "Compile-time polymorphism: function overload." << std::endl;
        CPPoly.func(10);
        CPPoly.func(7.93);
        CPPoly.func(10,15);
        return EXIT_SUCCESS;
    }

**Operator overloading**
C++ has the ability to provide the operators with a special meaning for a data type.

For example, it is known that the task of operator **+** is to add two operands. 

So a single operator **+**, when places between integer operands, adds them and when placed between string operands, concatenates them.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        std::cout << "Compile-time polymorphism: operator overload." << std::endl;
        complexNum Num1(5,3), Num2(4,7);
        complexNum Num3 = Num1 + Num2;
        Num3.print();
        return EXIT_SUCCESS;
    }

#### Runtime polymorphism.
This type of polymorphism is achieved by function overriding.

**Late binding** or **dynamic polymorphism** are other names for runtime polymorphism.

The function call is resolve at runtime.

**Function Overriding**.

This occurs when a derived class has definition for one of the member functions of the base class. That base function is said to be overriding.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        std::cout << "Runtime polymorphism: function overriding with data members." << std::endl;
        sports football = voleiball();
        std::cout << football.members << std::endl;
        return EXIT_SUCCESS;
    }

**Virtual function**

Is a member function that is declared in the base class using  the keyword virtual and is re-defined (overriden) in the derived class.

Virtual functions are dynamic in nature.

They are defined by inserting the keyword "virtual" inside a base class and are always declared with the base class and overridden in a child class.

Virtual functions are called during runtime (Late binding).

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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
        std::cout << "Runtime polymorphism: virtual function." << std::endl;
        Base* master;
        Derived slave;
        master = &slave;
        master->display();
        master->print();
        return EXIT_SUCCESS;
    }

### Encapsulation.
Is defined as binding together the data and the functions that manipulate them.

**Properties of Encapsulation**

**Data Proteccion**: Encapsulation protects the internal state of an object by keeping its data members private.

Access to and modification of these data members is restricted to the class's public methods, ensuring controlled and secure data manipulation.

**Information Hidding**: Encapsulation hides the internal implementation details of a class from external code. 

Only the public interface of the class is accessible, providing abstraction and simplifying the usage of the class
while allowing the internal implementation to be modified without impacting external code.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        int n;
        std::cout << "Example of encasulation, type any value: " << std::endl;
        std::cin >> n;
        example value;
        int retVal = value.solve(n);
        std::cout << "Return value from class: " << retVal << std::endl;
        return EXIT_SUCCESS;
    }

**Features of encapsulation**

We can not access any function from the class directly. We need and object to access that function that is using the member variables of that class.

The function which we are making inside the class must use only member variables. This is called encapsulation.

If a function is not inside the class which is using the member variable of the class the we don't call it encapsulation.

Encapsulation improves readability, maintainability and security by grouping data and methods together.

Helps to control data members modification.

    #include <iostream>
    #include <cstdlib>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        std::cout << "Example2 of encasulation" << std::endl;
        Person person("Ninmah Martinez",5);
        std::cout << "Name: " << person.getName() << std::endl;
        std::cout << "Name: " << person.getAge() << std::endl;
        person.setName("Carlos Martinez");
        person.setAge(37);
        std::cout << "Name: " << person.getName() << std::endl;
        std::cout << "Name: " << person.getAge() << std::endl;
        return EXIT_SUCCESS;
    }

Encapsulation can be implemented using classes and access modifiers.

    #include <iostream>
    #include <cstdlib>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        std::cout << "Example3 of encapsulation" << std::endl;
        Encapsulation obj;
        obj.set(10);
        std::cout << "Value of 'x': " << obj.get() << std::endl;
        return EXIT_SUCCESS;
    }

**Role of access specifiers in encapsulation**.

**Private**: Private access specifier means that the member function or data member can only be accessed by other member functions of the same class.

**Protected**: A protected access specifier means that the member function or data member can be accessed by other member functions of the same class or by derived classes.

**Public**: Public access specifier means that the member function or data member can be accessed by any code. 

By default, all data members and member functions of a class are made private by the compiler.

    #include <iostream>
    #include <cstdlib>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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
        std::cout << "Example4 of encapsulation" << std::endl;
        Circle circle;
        circle.getRadius();
        circle.findArea();
        return EXIT_SUCCESS;
    }

### Abstraction.
It means displaying only essential information and ignoring details.

**Data abstraction** refers to providing only essential information about the data o the outside, ignoring unnecessary details or implementation.

**Control abstraction** means displaying only essential information about implementation and ignoring unnecessary details.

**Abstraction using classes**

The classes help us to group data members and member functions using available access specifiers.

A class can decide which date member will be visible to the outside world ans which is not.

**Abstraction in header files**

Consider the pow() method present in math.h header file. Whenever we need to calculate the power of a number, we simply call the function pow() and pass 
the numbers as arguments without knowing the underlying algorithm.

**Abstraction using access specifiers**

These are the main pillar of implementing abastraction in C++. We can use access specifiers to enforce restrictions on class members.

Members declared as **public** in a class can be accessed fron anywhere in the program.

Members declared as **private** in a class, can be accessed only from within the class. They are no allowed to be accessed from any part of the code outside the class.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class Abstraction
    {
        private:
            int a,b;
        public:
            void set (int x, int y)
            {
                a=x;
                b=y;
            }
            void display ()
            {
                std::cout << "Value of a: " << a << std::endl;
                std::cout << "Value of b: " << b << std::endl;
            }
    };

    int main (int argc, char** argv)
    {
        Abstraction obj;
        obj.set(5,4);
        obj.display();
        return EXIT_SUCCESS;
    }

**Advantages of Data Abstraction**

Helps user to avoid writting low-level code.

Avoids code duplication and increases reusability.

Can change the internal implementation of the class indenpendently without affecting the user.

Helps increase the security of an aplication, only important details are provided to the user.

It reduces the complexity as well as the redundancy of the code, therefore increasing the readability.

New features or changes can be added to the system with minimal impact on existing code.

## **7.-** Which are the differences between Classes and Structs?
A structure will by default not hide its implementation details from whoever uses it in code, while a class by default hides all its implementation detailsans will therefore by default prevent programmer from accessing them.

Inheritance is posible with clases and structures.

| **Class**                                            | **Struct**                                           |
|------------------------------------------------------|------------------------------------------------------|
| Members of a class are private by default.           | Members of a structure are public by default.        |
| It is declared using **class** keyword.              | It is declared using the struct keyword.             |
| It is used for data abstraction and inheritance.     | It is used for grouping different datatypes.         |

**Class sintax**.

    class class_name
    {
        data_member;
        member_function;
    };

o

    class class_name
    {
        private:
            data_member1;
            data_member2;
        public:
            data_member3;
            member_function;
    };

**Struct sintax**.

    struct structure_name
    {
        structure_member1;
        structure_member2;
    };

### Examples.

Class:

    #include <iostream>

    class test
    {
        int x; /* x is private by default. */
    };

    int main ()
    {
        test t;
        t.x = 20; /* Will give us a compilation error. */
        return 0;
    }

Struct:

    #include <iostream>

    struct test
    {
        int x; /* x is public by default. */
    };

    int main ()
    {
        test t;
        t.x = 20;
        return 0;
        std::cout << t.x << std::endl; /* Will display '20'. */
    }

## **8.-** Which are the differences between C and C++ structures?
| **C Struct**                                                                   | **C++ Struct**                                       |
|------------------------------------------------------                          |------------------------------------------------------|
| Only data members are allowed, no functions allowed.                           | Can hold both: member functions and data members.    |
| Cannot have static members.                                                    | Can have static members.                             |
| Cannot have a constructor inside a structure.                                  | Constructor creation is allowed.                     |
| Direct initialization of data members is not possible.                         | Direct initialization of date members is possible.   |
| Writing the 'struct' keyword is necessary to declare structure-type variables. | Writing the 'struct' keyword is not necessary to declare structure-type variables. |
| Do not have access modifiers.                                                  | Supports access modifiers.                           |
| Only pointer to structs area allowed.                                          | Can have both pointers and references to the struct. |
| Sizeof operator will generate 0 for an empty structure.                        | Sizeof operator will generate 1 for an empty structure|
| Data hiding is not possible.                                                   | Data hiding is posible.                               |

Both C and C++, members of the struct have public visibilty by default.

## **9.-** What is a constructor?
Is a special method that is invoked automatically at the time an object of a class is created.

It is used to initialize the date members of new objects generally.

The constructor has the same name of the class or structure.

Constructors are mostly declared in the public section of the class thought they can be declared in the private section of the class.

Constructores do not return values; hence they do not have a return type.

Constructors get called automatically when we create the object of the class.

    class-name( parameters_list )
    {
        /* Constructor_definition. */
    }

Ejemplo:

    #include <iostream>

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

    int main (int argc, char** argv)
    {
        student s;
        s.display();
        return EXIT_SUCCESS;
    }

Defining constructor outside the class.

    class_name
    {
        /* Declaring the constructor. */
        /* Definition will be provided outside. */
        class_name();
        /* Defining remaining class. */
    }

    class_name: : clas_name (parameters list)
    {
        /* Constructor definition. */
    }

Ejemplo:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        player p;
        p.display();
        return EXIT_SUCCESS;
    }

### Types of constructors.
**Default constructor**: No parameters. They are used to create and object with default values.

    class_name()
    {
        /* Constructor body */
    }

**Parameterized constructor**; Takes parameters. Used to create an object with specific initial values.

    class_name (parameters...)
    {
        /* body */
    }

Ejemplo:

    #include <iostream>
    #include <cstdlib>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        gamer g (2,"Mely",100);
        g.display();
        return EXIT_SUCCESS;
    }

**Copy constructor**: Creates and object using another object of the same class. Used to create a copy of an object.

It is also called **member-wise initialization** because the copy cosntructor initializes one object with the existing object, both belonging to the same class on a **member-by-member** copy basis.

    class_name (const class_name &obj)
    {
        /* Copy logic */
    }

Ejemplo:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

    int main (int argc, char** argv)
    {
        A a1;
        a1.x = 10;
        std::cout << "a1, x = " << a1.x << std::endl;
        A a2(a1);
        std::cout << "a2, x = " << a1.x << std::endl;
        return EXIT_SUCCESS;
    }

**Move constructor**: Takes an **rvalue** reference to another object. Transfers resources from a temporary object.

It creates a new object from one that already exist of the same type, bt instead of making a copy of it, it makes the new object point to the already existing object in the memory, leaving the source object in a valid but unspecified state.

    class_name (class_name&& obj)
    {
        data = obj.data;
        /* Nulling pointer to the temporary data */
        obj.data = nullptr;
    }

Ejemplo:

    #include <iostream>
    #include <cstdlib>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

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

## **10.-** Difference between copy constructor and assigment operator?

The main difference is: copy constructor makes a new memory storage every time it is called while the assignment operator does not make new memory storage.

## **11.-** Can copy constructor be private?
Yes, a copy constructor can be made private. When a copy costructor is private inside a class, objects of that class become non-copyable.

This is particularly useful when the class has pointers or dynamically allocated resources.

## **12.-** Why copy constructor argument must be passed as a reference?
If the object is passed by value in the copy constructor, it will result in a recursive call to the copy constructor itself.

This happens because passing by value involves making a copy, and making a copy involves calling the copy constructor, leading to an infinite recursion.

Using reference avoids this recursion.

## **13.-** Why copy constructor argument should be const?

The reason for passing const reference is to avoid objects get modified accidentally.

## **14.-** When do we need a private constructor in C++?
### Restricting object cretion for all but friends, in this case all constructors have to be private.

    class A
    {
        private:
            A(){}

        public:
            friend class B;
    };

    class B
    {
        public:
            A* Create_A(){return new A;}
    }

### Restricting certain type of constructor.

    Class A
    {
        public:
            A();
            A(int);
        
        private:
            A(const A&);
            A(const A&) = delete;
    };

### To have a common delegate constructor, which is not supposed to be exposed to the outer worlds:

    Class A
    {
        private:
            int x_;
            A (const int x) : x_(x) {}
        
        public:
            A (const B& b) : A(b.x_) {}
            A (const C& c) : A(c.foo()) {}
    };

### For singleton patterns when the singleton class is not inheritible (if it is inheritible then used a protected constructor).

    class Singleton
    {
        public:
            static Singleton& getInstance() {
                Singleton object; // lazy initialization or use `new` & null-check
                return object;
            }
        private:
            Singleton() {}  // make `protected` for further inheritance
            Singleton(const Singleton&);  // inaccessible
            Singleton& operator=(const Singleton&);  // inaccessible
    };

