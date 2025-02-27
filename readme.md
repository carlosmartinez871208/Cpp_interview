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

## **15.-** What is a destructor?
It is an instance member function that is invoked automatically whenever an object is going to be destroyed.

The destructor is the last function called before an object is destroyed.

    ~ class_name()
    {
        /* Some instructions */
    }
or

    class_name
    {
        public:
            ~class_name();
    }

    class_name :: ~class_name()
    {
        /* Some instructions */
    }

The destructor destroys the class objects created by constructor.

Has the same name as tehir class name preceded by ~.

It is not possible to define more than one destructor.

Destructor cannot be overloaded.

it cannot be declared as static or const.

Destructor neither requires any argument, not returns any value.

It is automatically called when an object goes out of the scope.

Objects are destroyed in the reverse of an object creation.

Objects do not take any argument and do not return any value.

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    static int count = 0;

    class Test
    {
        public:
            Test()
            {
                count++;
                std::cout << "Object created: " << count << std::endl;
            }

            ~Test()
            {
                std::cout << "Object destroyed: " << count << std::endl;
                count--;
            }
    };

    int main (int argc, char** argv)
    {
        Test t, t1, t2, t3;
        return EXIT_SUCCESS;
    }

## **16.-** When a destructor is called?
It is called automatically when the object goes out of the scope or is deleted.

It is called when function ends.

It is called when program ends.

It is called when a block containing local variables ends.

It is called when a delete operator is called.

## **17.-** When is required to write a user-defined destructor?
The default constructor works fine unless we have dynamically allocated memoery or pointer in class.

When a class contains a pointer to memory allocated in the class, a destructor should be written to release memoery before the class instances is destroyed to avoid memory leaks.

## **18.-** Can a destructor be virtual?
Yes, when deleting a derived class object using a pointer of a base class type that has a non-virtual destructor results in undefined behavior.

To correct this situation, the base class should be defined with a virtual destructor.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    static int count = 0;

    class Base
    {
        public:
            Base(){std::cout << "Constructing base!" << std::endl;}
            virtual ~Base(){std::cout << "Destructing base!" << std::endl;}
    };

    class Derived : public Base{
        public:
            Derived(){std::cout << "Constructing derived!" << std::endl;}
            ~Derived(){std::cout << "Destructing derived!" << std::endl;}
    };

    int main (int argc, char** argv)
    {
        Derived *d = new Derived();
        Base *b = d;
        delete b;
        return EXIT_SUCCESS;
    }

As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor (even if it does nothing). This way, you ensure against any surprises later.

## **19.-** What is the use of a private destructor?
Whenever we want to control the destruction of objects of a class, the destructor shall be private.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class parent
    {
        ~parent(){std::cout << "Destructor called" << std::endl;}
        public:
            parent(){std::cout << "Constructor called" << std::endl;}
            void destruct() {delete this;}
    };

    int main (int argc, char** argv)
    {
        parent* p;
        p = new parent;
        p->destruct;
        return EXIT_SUCCESS;
    }

## **20.-** Can a constructor be private?
Yes, constructor can be defined in private section of class.

The class can be instantiated by a friend class.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class A
    {
        private:
            A(){std::cout << "A constructor!" << std::endl;}
        friend class B;
    };

    class B
    {
        public:
            B()
            {
                A a1;
                std::cout << "B constructor!" << std::endl;
            }
    }

    int main (int argc, char** argv)
    {
        B b1;
        return EXIT_SUCCESS;
    }

## **21.-** What is the scope resolution operator?
**::** is used to access the identifiers such as variable names and function names defined inside some other scope in the current scope.

    scope_name :: identifier

Aplications of Scope Resolution operator:

Accessing Global Variables.

    #include <iostream>
    using namespace std;

    // Global x
    int x = 3;

    int main() {
      
        // Local x
        int x = 10;
  
        // Printing the global x
        cout << ::x;
  
        return 0;
    }

Name space resolution.

    #include <iostream>
    using namespace std;

    // A sample namespace with a variable
    namespace N {
        int val = 10;
    };

    int main() {
      // Accessing val from namespace N
        cout << N::val;

        return 0;
    }

Define Class member function outside class.

    #include <iostream>
    using namespace std;

    // A sample class
    class A {
    public:
        // Only declaration of member function
        void fun();
    };

    // Definition outside class by referring to it
    // using ::
    void A::fun() {
        cout << "fun() called";
    }

    int main() {
        A a;
        a.fun();
        return 0;
    }

Access class static members.

    #include<iostream>
    using namespace std;

    class A {
    public:
        static int x; 
    };

    // In C++, static members must be explicitly defined 
    // like this
    int A::x = 1;

    int main() {
        // Accessing static data member
        cout << A::x;
        return 0;
    }

Refer to base class member in derived class.

    #include <iostream>
    using namespace std;

    class Base {
    public:
        void func() {
            cout << "Base class func()" << endl;
        }
    };

    class Derived : public Base {
    public:
        // Overridden function
        void func() {
            cout << "Derived class func()" << endl;
        }
    };

    int main() {
        Derived obj;
        // Calling base class's func() from the object of
        // derived class
        obj.Base::func();
        obj.func();
        return 0;
    }

## **22.-** What is a friend class?
This type of class can access private and protected members from other classes in which it is declared as a friend.

It is sometimes useful to allow a particular class to access private and protected members from other classes.

    friend class clas_name; /* Declared in base class. */

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class Base
    {
        private:
            int private_variable;
    
        protected:
            int protected_variable;
    
        public:
            Base()
            {
                private_variable = 10;
                protected_variable = 99;
            }

            friend class F;
    };

    class F
    {
        public:
            void display(Base& base)
            {
                std::cout << "Private variable value = " << base.private_variable << std::endl;
                std::cout << "Protected variable value = " << base.protected_variable << std::endl;
            }
    };

    int main (int argc, char** argv)
    {
        Base base;
        F f;
        f.display(base);
        return EXIT_SUCCESS;
    }

## **23.-** what is a friend function?
Like a friend class, a friend function can be granted special access to private and protected members of a class in C++.

They are not the member function of the class but can access and manipulate the private ans protected members of that class for they are declared as friends:

A friend function can be :

### A global function.

    friend return_type function_name (arguments); /* For a global function. */

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class Base
    {
        private:
            int private_variable;
    
        protected:
            int protected_variable;
    
        public:
            Base()
            {
                private_variable = 10;
                protected_variable = 99;
            }

            friend void friendFunction (Base& obj);
    };

    void friendFunction(Base& obj);

    int main (int argc, char** argv)
    {
        Base obj1;
        friendFunction(obj1);
        return EXIT_SUCCESS;
    }

    void friendFunction(Base& obj)
    {
        std::cout << "Private variable = " << obj.private_variable << std::endl;
        std::cout << "Protected variable = " << obj.protected_variable << std::endl;
    }

### A member function of another class.

    friend return_type class_name::function_name (arguments); /* For a member function of another class. */

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class A;

    class anotherClass
    {
        public:
            void memberFunction(A& obj);
    };

    class A
    {
        private:
            int private_variable;

        protected:
            int protected_variable;

        public:
            A()
            {
                private_variable = 10;
                protected_variable = 99;
            }

            friend void anotherClass::memberFunction(A&);
    };

    void anotherClass::memberFunction(A& obj)
    {
        std::cout << "Private variable = " << obj.private_variable << std::endl;
        std::cout << "Protected variable = " << obj.protected_variable << std::endl;
    }

    int main (int argc, char** argv)
    {
        A obj1;
        anotherClass obj2;
        obj2.memberFunction(obj1);
        return EXIT_SUCCESS;
    }

## **24.-** Which are some features of Friend Functions?

A friend function is a special function in C++ that in spite of not being a member function of a class has the privilege to access the private and protected data of a class.

A friend function is a non-member function or ordinary function of a class, which is declared as a friend using the keyword “friend” inside the class. By declaring a function as a friend, all the access permissions are given to the function.

The keyword “friend” is placed only in the function declaration of the friend function and not in the function definition or call.

A friend function is called like an ordinary function. It cannot be called using the object name and dot operator. However, it may accept the object as an argument whose value it wants to access.

A friend function can be declared in any section of the class i.e. public or private or protected.

A friend function is able to access members without the need of inheriting the class.

A friend function acts as a bridge between two classes by accessing their private data.

A friend function can be used to increase the versatility of overloaded operators.

A friend function can be declared either in the public or private or protected part of the class.

Friends should be used only for limited purposes. Too many functions or external classes are declared as friends of a class with protected or private data access lessens the value of encapsulation of separate classes in object-oriented programming.

Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.

## **25.-** Mention dissadvantages of friends funtions?

Friend functions have access to private members of a class from outside the class which violates the law of data hiding.

Friend functions cannot do any run-time polymorphism in their members.

## **26.-** What is a virtual function?
Also known virtual method is a member function thta is declared within a base class and is redefined (overriden) by a derived class.

When there is a reference to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the method.

### Features of a virtual function.
Virtual functions ensure thta the correct function is called for an object, regardless of the type of reference (or pointer) used for the function call.

They are mainly used to achieve Runtime polymorphism: this is achieve only through a pointer of the base class type.

Functions are declared with virtual keyword in a base class.

The reoslving of a function call is done at runtime.

### Rules for virtual functions.
Virtual functions cannot be static.

A virtual function can be a friend function of another class.

Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.

The prototype of virtual functions should be the same in the base as well derived class.

They are always defined in the base class and overriden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.

A class can have a virtual destructor but it cannot have a virtual constructor.

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class Base
    {
        public:
            virtual void print(){std::cout << "Print base class" << std::endl;}
            void show(){std::cout << "Show base class" << std::endl;}
    };

    class Derived : public Base
    {
        public:
            void print(){std::cout << "Print Derived class" << std::endl;}
            void show(){std::cout << "Show Derived class" << std::endl;}
    };

    int main (int argc, char** argv)
    {
        Base* bptr;
        Derived d;
        bptr = &d;
        /* Virtual function, binded at runtime */
        bptr->print();
        /* Non virtual function, binded at compile time */
        bptr->show();
        return EXIT_SUCCESS;
    }

## **27.-** Mention some virtual function limitations?
**Slower**: The function call takes slightly longer due to the virtual mechanism and makes it more difficult fr the compiler to optimize because it does not know exactly which funtion is going to be called at compile time.

**Difficult to Debug**: In a complex system, virtual functions can make it little more difficult to figure out where a function is being called from.

## **28.-** What is a smart pointer?
It is a wrapper class over a pointer with an operator like **\*** and **->**. Since the destructor is automatically called when an object goes out of scope, the dynamically allocated memory would automatically be deleted.

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    class SmartPtr
    {
        int* ptr;

        public:
            explicit SmartPtr(int* p = nullptr){ptr=p;}

            ~SmartPtr() {delete(ptr);}

            int& operator*() {return *ptr;}
    };

    int main (int argc, char** argv)
    {
        SmartPtr ptr(new int());
        *ptr = 20;
        std::cout << *ptr << std::endl;
        return EXIT_SUCCESS;
    }

## **29.-** Mention difference between pointers and smart pointers.

| **Pointer**                                                    | **Smart pointer**                                    |
|----------------------------------------------------------------|------------------------------------------------------|
| A pointer is a variable that mantains a memory address.        | It's pointer-wrapping stack-allocated object.        |
| A pointer is a variable that points to something in memory.    | Smart pointers, are classed that wrap a pointer or scoped pointers|
| It is not destroyed in any form when it goes out of its scope. | It destroys it self whe it goes out of its scope.    |
| Pointers are not so efficient as they don't support any other feature | Smart pointers are more efficients as they have an additional feature of memory management|
| They are very labor-centic/manual.                             | They are automatic/pre-programmed in nature.        |

## **30.-** Which are the smart pointer types?
### auto_ptr: 
C++11 deprecated, similar to unique but less security.

### unique_ptr: 
Stores one pointer. We can assign different object by removing the current object from the pointer.

Example:

    #include <iostream>
    // Dynamic Memory management library
    #include <memory>

    class Rectangle {
        int length;
        int breadth;

    public:
        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area() { return length * breadth; }
    };

    int main()
    {
    // --\/ Smart Pointer
        unique_ptr<Rectangle> P1(new Rectangle(10, 5));
        cout << P1->area() << endl; // This'll print 50

        // unique_ptr<Rectangle> P2(P1);
        unique_ptr<Rectangle> P2;
        P2 = move(P1);

        // This'll print 50
        cout << P2->area() << endl;
        return 0;
    }

### Shared pointer.
More than one pointer can point to this one object at a time and it will maintain a reference counter using the use_count() method.

Example:

    #include <iostream>
    // Dynamic Memory management library
    #include <memory>

    class Rectangle {
        int length;
        int breadth;

    public:
        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area() { return length * breadth; }
    };

    int main()
    {
        //---\/ Smart Pointer
        shared_ptr<Rectangle> P1(new Rectangle(10, 5));
        // This'll print 50
        cout << P1->area() << endl;

        shared_ptr<Rectangle> P2;
        P2 = P1;

        // This'll print 50
        cout << P2->area() << endl;

        // This'll now not give an error,
        cout << P1->area() << endl;

        // This'll also print 50 now
        // This'll print 2 as Reference Counter is 2
        cout << P1.use_count() << endl;
        return 0;
    }

### weak_ptr
This holds a non-owning reference to an object. It is similar ti shared_pointer except it will not mantain a reference counter.

In this case, a pointer will not have a stronghold on the project. The reason is to avoid the circular dependency created by two or more object pointing to each other using shared_ptr.

    #include <iostream>
    // Dynamic Memory management library
    #include <memory>

    class Rectangle {
        int length;
        int breadth;

    public:
        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area() { return length * breadth; }
    };

    int main()
    {
        //---\/ Smart Pointer
        shared_ptr<Rectangle> P1(new Rectangle(10, 5));
  
        // create weak ptr
        weak_ptr<Rectangle> P2 (P1);
  
        // This'll print 50
        cout << P1->area() << endl;

        // This'll print 1 as Reference Counter is 1
        cout << P1.use_count() << endl;
        return 0;
    }

## **31.-** What is a template?
It is a tool and the idea is to pass the data type as a parameter so that we don't need to write the same code for differente data types.

Templates are expanded at compiler time (like macros), the difference with macros is that the compiler does type-checking before template expansion.

The idea is that source code contains only function/class, but compiled code may contain multiples copies of the same function/class.

### Function templates.
The goal is to write a function that can be used for different dta types.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    template <typename T> T myMax(T x, T y)
    {
        return (x>y)?x:y;
    }

    int main (int argc, char** argv)
    {
        std::cout << myMax<int>(3,7) << std::endl;
        std::cout << myMax<double>(3.5,7.6) << std::endl;
        std::cout << myMax<char>('g','e') << std::endl;
        return EXIT_SUCCESS;
    }

### Class templates.
Defines class that is independent of the data type.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    template <typename T> class Array
    {
        private:
            T* ptr;
            int size;

        public:
            Array(T arr[], int s);
            void print();
    };

    template <typename T> Array<T> :: Array(T arr[], int s)
    {
        ptr = new T(s);
        size = s;
        for(int i=0; i<size; i++)
        {
            ptr[i] = arr[i];
        }
    }

    template <typename T> void Array<T> :: print()
    {
        for(int i=0; i<size; i++)
        {
            std::cout << *(ptr+i) << std::endl; 
        }
    }

    int main (int argc, char** argv)
    {
        int arr[5] = {1,2,3,4,5};
        Array<int> a(arr,5);
        a.print();
        return EXIT_SUCCESS;
    }

## **32.-** What is an exception?
It is an unexpected problem that arises during the execution of a program, the program terminates suddendly with some errors/issues.

Exception occurs in runtime.

There are two types of exception:

**synchronous**: Exceptions that happen whe something goes wrong because of a mistake in the input data or when the program is not equipped to handle tue current type of data it is working with, such as dividing a number by zero.

**Asynchronous**: Exception that are beyond the program's control, such as disc failure, keyboard interrupts, etc.

### Syntax.

    try
    {
        /* Code that might throw an exception */
        throw SomeExceptionType("Error message");
    }
    catch (ExceptionName e1)
    {
        /* catch block: catches the exception that is thrown from try block */
    }

### Example.

    #include <iostream>
    #include <stdexcept>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    int main (int argc, char** argv)
    {
        try
        {
            int numerator=10;
            int denominator=0;
            int res;
            if(0 == denominator)
            {
                throw std::runtime_error("Division by zero not allowed");
            }
            else
            {
                res  = numerator/denominator;
                std::cout << "Result: " << res <<std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        return EXIT_SUCCESS;
    }

## **33.-** What is a namespace?
**namespace** provide the space where identifiers (variables, method, classes) are defined or declared.

Using namespace you can define the space or context in which identifiers are defined.

A namespace defines a scope.

So, if a function called xyz() and there is another library available which has the same function xyz(). Now the compiler has no way of knowing which version of 
xyz() function has to be referred.

A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables, etc, with the 
same name available in different libraries.

The best example of namespace scope is the C++ standard library (std) where all the classes, methods and templates are declared.

### Definition of a namespace.

    namespace namespace_name
    {
        /* Code declarations */
        method (void add();) 
        classes (class student{};)
    } /* No semicolon */

### Using directive.
To avoid prepending namespaces with the **using** namespace directive.
This directive tells the compiler that the subsequent code is making use of names in the specified namespace.

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    namespace first_space
    {
        void func()
        {
            std::cout << "Inside first space" << std::endl;
        }
    }

    namespace second_space
    {
        void func()
        {
            std::cout << "Inside second space" << std::endl;
        }
    }

    using namespace first_space;

    int main (int argc, char** argv)
    {
        func();
        return EXIT_SUCCESS;
    }

### Nested Namespaces.
Namespaces can be nested where you can define one namespaces inside another spaces as follows:

    namespace namespace_name1
    {
        /* Code declaration */
        namespaces namespace_name2
        {
            /* Code declaration */
        }
    }

Example:

    #include <iostream>

    #ifndef EXIT_SUCCESS
     #define EXITS_SUCESS 0u
    #endif

    namespace first_space
    {
        void func()
        {
            std::cout << "Inside first space" << std::endl;
        }
        namespace second_space
        {
            void func()
            {
                std::cout << "Inside second space" << std::endl;
            }
        }
    }

    using namespace first_space::second_space;

    int main (int argc, char** argv)
    {
        func();
        return EXIT_SUCCESS;
    }

### Classes and namespaces.

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

## **34.-** What is a struct?
It is a user defined data type and it is used to group items of possibly different types into a single type.

### Syntax:

    struct structureName
    {
        member1;
        member2;
        .
        .
        .
        memberN;
    }

Structures contain two types of members:

**Data member**: These are normal C++ variables.

**Member functions**: These are members are normal C++ functions. Along with variables, we can also include functions inside a structure declaration.

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

## **35.-.-** What is a pointer?
A pointer is a symbolic representation of an address. It enable a program to simulate **call-by-reference** as well as to create and manipulate dynamic structures.

The address of the variable which it is assigned to the pointer variable that points to the same data type.

### Use of a pointer.
Define a pointer variable

Assign the address of a variable to a pointer using the unary operator **&** which returns the address of that variable.

Accessing the value stored in the address using unary operator **\*** which return the value of the variable located at the address specified by its operand.

The reason we associate data typw with a pointer is **that it knows how many bytes the data is stored in**.

When a pointer is incremented, the pointer is increased according the size of the data type which it points.

### Example:

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

## **36.-** Mention the ways to pass arguments to a function?
Call by value.
Call by reference with a pointer argument.
Call by reference with a reference argumente.

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

Output:

    Address of n1 in main(): 0xffffeb8d3a5c
    Value of n1 at pass_by_value: Address of n(n1) in pass_by_value function: 0xffffeb8d3a3c
    64
    No change in n1: 8
    Address of n2 in main(): 0xffffeb8d3a60
    Address of n(n2) in pass_by_reference_ptrArg function: 0xffffeb8d3a60
    Value of n2 at pass_by_reference_ptrArg: 64
    Change reflected in n2: 64
    Address of n3 in main(): 0xffffeb8d3a64
    Address of n(n3) in pass_by_reference_refArg function: 0xffffeb8d3a64
    Value of n3 at pass_by_reference_ptrArg: 64
    Change reflected in n3: 64

## **37.-** Explain dynamic memory.
Refers to perfomring memory allocation by a programmer,

Dynamically allocated memory is allocated on Heap, and non-static and local variables get memoery allocated on Stack.

For normal variables like "int a", "char str[10]", memoery is automatically allocated and deallocated. For dynamically allocated memory like "int *p = new int [10]", it is the programmer responsability to deallocate memoery when no longer needed. If programmer does not deallocate memory, it causes a memory leak (memory is not deallocated until program ends).

### new operator.
It denotes a request for memory allocation on the free store if enought memory is available.

**new** operator initializes the memory and returns the address of the newly allocated and initialized memoery to the pointer variable:

    pointer-variable = new data-type;

Initialize:

    pointer-variable = new data-type(value);

### delete operator.
It is use to deallocate dynamic memory.

    delete pointer-variable;

### Example:

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

## **38.-** What is lambda expresion?
A lambda is an unnamed function that is useful for short snippets of code that are impossible to reuse and are not worth naming.

[]{} /* Lambda with no parameters that does nothing */

[] is the capture list and {} the function.

The full syntax for lambda-expression, including attributes, noexcept/throw-specifications, requires-clauses, etc. is more complex.

The capture list defines what from the outside of the lambda should be available inside the function body and how

1.- A value: [x]
2.- A reference [&x]
3.- Any variable currently in scope by reference [&]
4.- Same as 3, but by value [=]
5.- Capturing **this** and making member functions callable within the lambda [this]
6.- Combine any of the above in a comma separated list [x, &y]

An element of the capture can now be initialized with **=**, which is called **init-capture**. This allows renaming of variables and to capture by moving.

    int x = 4;
    auto y = [&r = x, x = x+1]()->int {
                r+=2;
                return x+2;
             }

### Example.

    #include <algorithm>
    #include <functional>
    #include <iostream>
    #include <vector>
 
    int main()
    {
        std::vector<int> c{1, 2, 3, 4, 5, 6, 7};
        int x = 5;
        c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());
 
        std::cout << "c: ";
        std::for_each(c.begin(), c.end(), [](int i) { std::cout << i << ' '; });
        std::cout << '\n';
 
        // the type of a closure cannot be named, but can be inferred with auto
        // since C++14, lambda could own default arguments
        auto func1 = [](int i = 6) { return i + 4; };
        std::cout << "func1: " << func1() << '\n';
 
        // like all callable objects, closures can be captured in std::function
        // (this may incur unnecessary overhead)
        std::function<int(int)> func2 = [](int i) { return i + 4; };
        std::cout << "func2: " << func2(6) << '\n';
 
        constexpr int fib_max {8};
        std::cout << "Emulate `recursive lambda` calls:\nFibonacci numbers: ";
        auto nth_fibonacci = [](int n)
        {
            std::function<int(int, int, int)> fib = [&](int n, int a, int b)
            {
                return n ? fib(n - 1, a + b, a) : b;
            };
            return fib(n, 0, 1);
        };
 
        for (int i{1}; i <= fib_max; ++i)
            std::cout << nth_fibonacci(i) << (i < fib_max ? ", " : "\n");
 
        std::cout << "Alternative approach to lambda recursion:\nFibonacci numbers: ";
        auto nth_fibonacci2 = [](auto self, int n, int a = 0, int b = 1) -> int
        {
            return n ? self(self, n - 1, a + b, a) : b;
        };
 
        for (int i{1}; i <= fib_max; ++i)
            std::cout << nth_fibonacci2(nth_fibonacci2, i) << (i < fib_max ? ", " : "\n");
 
    #ifdef __cpp_explicit_this_parameter
        std::cout << "C++23 approach to lambda recursion:\n";
        auto nth_fibonacci3 = [](this auto self, int n, int a = 0, int b = 1) -> int
        {
            return n ? self(n - 1, a + b, a) : b;
        };
 
        for (int i{1}; i <= fib_max; ++i)
            std::cout << nth_fibonacci3(i) << (i < fib_max ? ", " : "\n");
    #endif
    }