#include <iostream>

class Base
{
public:
    // Virtual function
    virtual void show()
    {
        std::cout << "Base class show function" << std::endl;
    }

    // Virtual destructor
    virtual ~Base()
    {
        std::cout << "Base class destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    // Overriding virtual function
    void show() override
    {
        std::cout << "Derived class show function" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived class destructor" << std::endl;
    }
};

int main()
{
    // Base *b1 = new Base();
    // b1->show();
    // delete b1;

    //When dealing with inheritance and polymorphism in C++, it's common to have a base class pointer pointing to a derived class object. If the base class destructor is not virtual, deleting the derived class object through the base class pointer can lead to incomplete destruction of the derived class object, causing resource leaks or undefined behavior.

    Base *b = new Derived();
    b->show(); // Calls Derived class show function due to virtual keyword
    delete b;  // Calls both Derived and Base class destructors
    return 0;
}










// #include <iostream>

// class Base {
// public:
//     ~Base() {
//         std::cout << "Base destructor called" << std::endl;
//     }
// };

// class Derived : public Base {
// public:
//     ~Derived() {
//         std::cout << "Derived destructor called" << std::endl;
//     }
// };

// int main() {
//     Base* b = new Derived();
//     delete b; // Undefined behavior, only Base destructor is called
//     return 0;
// }

// When delete b is called, it only calls the Base destructor, and the Derived destructor is not called.
// This can lead to resource leaks if the Derived class manages resources that need to be released in its destructor.