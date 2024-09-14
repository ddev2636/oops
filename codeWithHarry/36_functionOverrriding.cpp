#include <iostream>
using namespace std;

class Base
{
public:
    // Virtual function in the base class
    virtual void display()
    {
        cout << "Display from Base class" << endl;
    }

    // Virtual destructor in the base class
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    // Override the virtual function in the derived class
    void display() override
    {
        cout << "Display from Derived class" << endl;
    }
};

int main()
{
    Base *basePtr;         // Pointer to Base class
    Derived derivedObj;    // Object of Derived class
    basePtr = &derivedObj; // Base class pointer pointing to Derived class object

    basePtr->display(); // Calls the overridden function in Derived class

    return 0;
}
