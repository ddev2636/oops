#include <iostream>
#include <vector>
using namespace std;

// Need for Base Class Pointers to Derived Objects

// Polymorphism:

// Polymorphism allows you to use a base class pointer or reference to call derived class methods. This is useful when you want to write functions or classes that can operate on objects of different derived classes through a common interface provided by the base class.
// By defining a base class pointer and assigning it to a derived class object, you enable the use of polymorphism. The base class pointer can be used to access derived class objects, allowing you to write code that works with different types of derived objects in a uniform way.

// Flexibility and Extensibility:

// Using base class pointers makes your code more flexible and easier to extend. You can add new derived classes without changing the existing code that uses the base class pointers. This makes your codebase more maintainable and extensible.
// For instance, you can write functions that take base class pointers as parameters and handle different derived class objects. This allows you to add new derived classes later without modifying the function implementations.

// Dynamic Binding:

// When you use a base class pointer to call a function, dynamic binding (or late binding) ensures that the correct function implementation is called based on the actual object type at runtime. This is achieved through the use of virtual functions.
// For example, if you have a base class pointer pointing to a derived class object, calling a virtual function will invoke the derived class's version of the function, even if the pointer is of base class type.

// Base class
class Shape
{
public:
    virtual void draw() const
    {
        cout << "Drawing a shape" << endl;
    }

    virtual ~Shape() {}
};

// Derived classes
class Circle : public Shape
{
public:
    void draw() const override
    {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() const override
    {
        cout << "Drawing a rectangle" << endl;
    }
};

void drawShapes(const vector<Shape *> &shapes)
{
    for (const Shape *shape : shapes)
    {
        shape->draw(); // Calls the correct derived class's draw method
    }
}

int main()
{
    vector<Shape *> shapes;

    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());

    drawShapes(shapes); // Polymorphic behavior: draws both Circle and Rectangle

    // Clean up
    for (Shape *shape : shapes)
    {
        delete shape;
    }

    return 0;
}
