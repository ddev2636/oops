#include <iostream>

// Even though the destructor is pure virtual, it must still be defined. This is because destructors are always called in the reverse order of construction (from derived to base), and the base class destructor needs to perform any necessary cleanup.
class Base
{
public:
    virtual ~Base() = 0; // Pure virtual destructor
};

Base::~Base()
{
    // Definition of pure virtual destructor
    std::cout << "Base destructor called" << std::endl;
}

class Derived : public Base
{
public:
    ~Derived() override
    {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main()
{
    Base *b = new Derived();
    delete b; // Outputs: Derived destructor called followed by Base destructor called

    return 0;
}
