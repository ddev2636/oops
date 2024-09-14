// compile time(static)

//******function overloading**********
// #include <iostream>

// class Print {
// public:
//     void show(int i) {
//         std::cout << "Integer: " << i << std::endl;
//     }

//     void show(double d) {
//         std::cout << "Double: " << d << std::endl;
//     }

//     void show(const std::string& s) {
//         std::cout << "String: " << s << std::endl;
//     }
// };

// int main() {
//     Print p;
//     p.show(5);
//     p.show(5.5);
//     p.show("Hello");
//     return 0;
// }

// operator overloading
// #include <iostream>

// class Complex
// {
// public:
//     Complex(int r, int i) : real(r), imag(i) {}

//     Complex operator+(const Complex &other)
//     {
//         return Complex(real + other.real, imag + other.imag);
//     }

//     void display()
//     {
//         std::cout << real << " + " << imag << "i" << std::endl;
//     }

// private:
//     int real, imag;
// };

// int main()
// {
//     Complex c1(3, 4), c2(1, 2);
//     Complex c3 = c1 + c2;
//     c3.display();
//     return 0;
// }



//Runtime polymorphism
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show " << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    Derived* d = new Derived();
    d->show();
    b->show(); // Calls Derived's show method
    delete b;
    return 0;
}

