#include <iostream>

class Example
{
public:
    Example()
    {
        std::cout << "Object created." << std::endl;
    }

    ~Example()
    {
        std::cout << "Object destroyed." << std::endl;
    }

    void display()
    {
        std::cout << "Displaying object data." << std::endl;
    }
};

int main()
{
    // Dynamically allocate an object of Example class
    Example *obj = new Example(); // Memory allocated on the heap

    // Use the object
    obj->display();

    // Memory leak: 'delete obj' is missing here, so the object is not destroyed.

    return 0; // Program exits without releasing the dynamically allocated memory
}
