#include <iostream>

class A
{
public:
    void displayA()
    {
        std::cout << "Class A" << std::endl;
    }
};

class B
{
public:
    void displayB()
    {
        std::cout << "Class B" << std::endl;
    }
};

class C : public A, public B
{
public:
    void displayC()
    {
        std::cout << "Class C" << std::endl;
    }
};

int main()
{
    C obj;
    obj.displayA(); // Inherited from class A
    obj.displayB(); // Inherited from class B
    obj.displayC(); // Member of class C

    return 0;
}
