#include <iostream>
#include <stdexcept>
#include <vector>

// -----------------------------------------
// 1. Single Responsibility Principle (SRP)
// -----------------------------------------

// Incorrect Implementation (Violation of SRP)
class BadInvoice
{
public:
    void createInvoice()
    {
        std::cout << "Invoice created." << std::endl;
    }

    void printInvoice()
    {
        std::cout << "Printing invoice..." << std::endl;
    }

    void sendEmail()
    {
        std::cout << "Emailing invoice..." << std::endl;
    }
};

// Correct Implementation (Follows SRP)
class Invoice
{
public:
    void createInvoice()
    {
        std::cout << "Invoice created." << std::endl;
    }
};

class InvoicePrinter
{
public:
    void printInvoice(const Invoice &invoice)
    {
        std::cout << "Printing invoice..." << std::endl;
    }
};

class InvoiceEmailer
{
public:
    void sendEmail(const Invoice &invoice)
    {
        std::cout << "Emailing invoice..." << std::endl;
    }
};

// -----------------------------------------
// 2. Open/Closed Principle (OCP)
// -----------------------------------------

// Incorrect Implementation (Violation of OCP)
class BadShape
{
public:
    virtual int area() = 0;
};

class BadRectangle : public BadShape
{
    int width, height;

public:
    BadRectangle(int w, int h) : width(w), height(h) {}
    int area() override
    {
        return width * height;
    }
};

class BadCircle : public BadShape
{
    int radius;

public:
    BadCircle(int r) : radius(r) {}
    int area() override
    {
        return 3.14 * radius * radius;
    }
};

class BadAreaCalculator
{
public:
    int calculateArea(BadShape *shape)
    {
        // Hardcoded for Rectangle and Circle only
        if (dynamic_cast<BadRectangle *>(shape))
        {
            return dynamic_cast<BadRectangle *>(shape)->area();
        }
        else if (dynamic_cast<BadCircle *>(shape))
        {
            return dynamic_cast<BadCircle *>(shape)->area();
        }
        return 0;
    }
};

// Correct Implementation (Follows OCP)
class Shape
{
public:
    virtual int area() = 0; // Open for extension, closed for modification
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() override
    {
        return width * height;
    }
};

class Circle : public Shape
{
    int radius;

public:
    Circle(int r) : radius(r) {}
    int area() override
    {
        return 3.14 * radius * radius;
    }
};

class Triangle : public Shape
{
    int base, height;

public:
    Triangle(int b, int h) : base(b), height(h) {}
    int area() override
    {
        return (base * height) / 2;
    }
};

class AreaCalculator
{
public:
    int calculateArea(Shape *shape)
    {
        return shape->area(); // Polymorphic behavior
    }
};

// -----------------------------------------
// 3. Liskov Substitution Principle (LSP)
// -----------------------------------------

// Incorrect Implementation (Violation of LSP)
class BadBird
{
public:
    virtual void fly()
    {
        std::cout << "Flying!" << std::endl;
    }
};

class BadPenguin : public BadBird
{
public:
    void fly() override
    {
        throw std::logic_error("Penguins can't fly!"); // Violates LSP
    }
};

// Correct Implementation (Follows LSP)
class Bird
{
public:
    virtual void move() = 0;
    virtual ~Bird() = default;
};

class FlyingBird : public Bird
{
public:
    void move() override
    {
        fly();
    }
    virtual void fly() = 0;
};

class NonFlyingBird : public Bird
{
public:
    void move() override
    {
        walk();
    }
    virtual void walk() = 0;
};

class Sparrow : public FlyingBird
{
public:
    void fly() override
    {
        std::cout << "Sparrow is flying!" << std::endl;
    }
};

class Penguin : public NonFlyingBird
{
public:
    void walk() override
    {
        std::cout << "Penguin is walking!" << std::endl;
    }
};

// -----------------------------------------
// 4. Interface Segregation Principle (ISP)
// -----------------------------------------

// Incorrect Implementation (Violation of ISP)
class BadIWorker
{
public:
    virtual void work() = 0;
    virtual void eat() = 0; // Not all workers need to eat
};

class BadRobot : public BadIWorker
{
public:
    void work() override
    {
        std::cout << "Robot working!" << std::endl;
    }

    void eat() override
    {
        // This doesn't make sense for a robot!
        std::cout << "Robots don't eat!" << std::endl;
    }
};

// Correct Implementation (Follows ISP)
class IWorker
{
public:
    virtual void work() = 0;
    virtual ~IWorker() = default;
};

class IHumanWorker : public IWorker
{
public:
    virtual void eat() = 0; // Only humans need to eat
};

class Human : public IHumanWorker
{
public:
    void work() override
    {
        std::cout << "Human working!" << std::endl;
    }

    void eat() override
    {
        std::cout << "Human eating!" << std::endl;
    }
};

class Robot : public IWorker
{
public:
    void work() override
    {
        std::cout << "Robot working!" << std::endl;
    }
};

// -----------------------------------------
// 5. Dependency Inversion Principle (DIP)
// -----------------------------------------

// Incorrect Implementation (Violation of DIP)
class BadLightBulb
{
public:
    void turnOn()
    {
        std::cout << "LightBulb turned on!" << std::endl;
    }

    void turnOff()
    {
        std::cout << "LightBulb turned off!" << std::endl;
    }
};

class BadSwitch
{
    BadLightBulb *light; // Direct dependency on a concrete class
public:
    BadSwitch(BadLightBulb *l) : light(l) {}

    void operate()
    {
        light->turnOn(); // Direct control over the LightBulb
    }
};

// Correct Implementation (Follows DIP)
class ISwitchable
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~ISwitchable() = default;
};

class LightBulb : public ISwitchable
{
public:
    void turnOn() override
    {
        std::cout << "LightBulb turned on!" << std::endl;
    }

    void turnOff() override
    {
        std::cout << "LightBulb turned off!" << std::endl;
    }
};

class Switch
{
    ISwitchable *device; // Dependency on abstraction (interface)
public:
    Switch(ISwitchable *dev) : device(dev) {}

    void operate()
    {
        device->turnOn(); // Indirect control via interface
    }
};

// Main function to demonstrate the code
int main()
{
    // 1. Single Responsibility Principle (SRP)
    std::cout << "Single Responsibility Principle (SRP):" << std::endl;
    Invoice invoice;
    InvoicePrinter printer;
    InvoiceEmailer emailer;

    invoice.createInvoice();
    printer.printInvoice(invoice);
    emailer.sendEmail(invoice);

    // 2. Open/Closed Principle (OCP)
    std::cout << "\nOpen/Closed Principle (OCP):" << std::endl;
    Rectangle rect(10, 5);
    Circle circ(3);
    Triangle tri(4, 7);

    AreaCalculator areaCalculator;
    std::cout << "Rectangle area: " << areaCalculator.calculateArea(&rect) << std::endl;
    std::cout << "Circle area: " << areaCalculator.calculateArea(&circ) << std::endl;
    std::cout << "Triangle area: " << areaCalculator.calculateArea(&tri) << std::endl;

    // 3. Liskov Substitution Principle (LSP)
    std::cout << "\nLiskov Substitution Principle (LSP):" << std::endl;
    Sparrow sparrow;
    Penguin penguin;

    Bird *flyingBird = &sparrow;
    flyingBird->move(); // Should fly

    Bird *nonFlyingBird = &penguin;
    nonFlyingBird->move(); // Should walk

    // 4. Interface Segregation Principle (ISP)
    std::cout << "\nInterface Segregation Principle (ISP):" << std::endl;
    Human human;
    Robot robot;

    human.work();
    human.eat();
    robot.work(); // No unnecessary 'eat' method for robot

    // 5. Dependency Inversion Principle (DIP)
    std::cout << "\nDependency Inversion Principle (DIP):" << std::endl;
    LightBulb bulb;
    Switch lightSwitch(&bulb);

    lightSwitch.operate(); // LightBulb controlled through ISwitchable

    return 0;
}
