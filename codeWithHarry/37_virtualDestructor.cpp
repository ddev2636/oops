#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor" << endl;
    }

    virtual ~Base()
    { // Virtual destructor
        cout << "Base destructor" << endl;
    }
};
// if the destructor of the base class is not virtual then derived destructor is not called

//  Resource Leak:
//  Because the Derived destructor is not called, the dynamically allocated resource (data) in Derived is not freed. This results in a memory leak.

// Polymorphism Issues:
// Without a virtual destructor in the base class, the destructor of the derived class is not executed, potentially leading to incomplete cleanup and resource leaks.

class Derived : public Base
{
private:
    int *data; // Dynamic resource

public:
    Derived(int value)
    {
        data = new int(value); // Allocate resource
        cout << "Derived constructor" << endl;
    }

    ~Derived()
    {                // Destructor for Derived class
        delete data; // Clean up the resource
        cout << "Derived destructor" << endl;
    }
};

int main()
{
    Base *basePtr = new Derived(10); // Create Derived object but use Base pointer

    delete basePtr; // Proper cleanup due to virtual destructor

    return 0;
}
