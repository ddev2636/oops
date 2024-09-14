#include <iostream>

class Base
{
public:
    virtual void show()
    {
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived final : public Base
{
public:
    void show() override
    {
        std::cout << "Derived class show function" << std::endl;
    }
};

// Uncommenting the following code will cause a compilation error
/*
class MoreDerived : public Derived {
public:
    void show() override {
        std::cout << "MoreDerived class show function" << std::endl;
    }
};
*/

int main()
{
    Base *b = new Derived();
    b->show();
    delete b;
    return 0;
}
