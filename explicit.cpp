// #include <iostream>

// class Complex {
// public:
//     // Constructor with one argument
//     Complex(int real, int imag = 0) : real(real), imag(imag) {}

//     void display() const {
//         std::cout << real << " + " << imag << "i" << std::endl;
//     }

// private:
//     int real;
//     int imag;
// };

// int main() {
//     Complex c1 = 5; // Implicit conversion
//     c1.display();   // Output: 5 + 0i

//     Complex c2(3, 4); // Direct initialization
//     c2.display();     // Output: 3 + 4i

//     return 0;
// }





#include <iostream>

class Complex {
public:
    // Explicit constructor
    explicit Complex(int real, int imag = 0) : real(real), imag(imag) {}

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

private:
    int real;
    int imag;
};

int main() {
    // Complex c1 = 5; // Error: no implicit conversion allowed
    Complex c1(5); // Direct initialization
    c1.display();  // Output: 5 + 0i

    Complex c2(3, 4); // Direct initialization
    c2.display();     // Output: 3 + 4i

    return 0;
}
