#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void getData()
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << imaginary << endl;
    }

    void setData(int a, int b)
    {
        real = a;
        imaginary = b;
    }
};
int main()
{
    Complex *ptr = new Complex(); // dynamic allocation

    (*ptr).setData(1, 54);
    (*ptr).getData();
    // the below code is exactly same as the above
    Complex *ptr = new Complex;
    ptr->setData(1, 54);
    ptr->getData();

    return 0;
}
