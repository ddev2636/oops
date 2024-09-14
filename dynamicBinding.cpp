#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }

    virtual ~Base() {} // Always good practice to make the destructor virtual
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show" << std::endl;
    }
};

void display(Base& b) {
    b.show();
}

int main() {
    Base b;
    Derived d;

    // Derived *c = new Derived();
    // display(c);

    // display(b); // Outputs: Base show
    // display(d); // Outputs: Derived show

    return 0;
}
