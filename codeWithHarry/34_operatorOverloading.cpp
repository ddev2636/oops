#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    // Constructor to initialize the complex number
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex &obj)
    {
        Complex temp;
        temp.real = real + obj.real; // Add real parts
        temp.imag = imag + obj.imag; // Add imaginary parts
        return temp;
    }

    // Overloading the << operator for output
    friend ostream &operator<<(ostream &out, const Complex &obj);
};

// Overloading the << operator to print the complex number
ostream &operator<<(ostream &out, const Complex &obj)
{
    out << obj.real;
    if (obj.imag >= 0)
    {
        out << " + " << obj.imag << "i";
    }
    else
    {
        out << " - " << -obj.imag << "i";
    }
    return out;
}

int main()
{
    Complex c1(3, 4);  // First complex number: 3 + 4i
    Complex c2(1, -2); // Second complex number: 1 - 2i

    // Add two complex numbers using overloaded + operator
    Complex c3 = c1 + c2;

    // Output the result using overloaded << operator
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;

    return 0;
}
