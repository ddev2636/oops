#include <iostream>
using namespace std;

class Display
{
public:
    // Function to display an integer
    void show(int i)
    {
        cout << "Integer: " << i << endl;
    }

    // Function to display a double
    void show(double d)
    {
        cout << "Double: " << d << endl;
    }

    // Function to display a string
    void show(const string &str)
    {
        cout << "String: " << str << endl;
    }

    // Function to display two integers
    void show(int i1, int i2)
    {
        cout << "Two integers: " << i1 << " and " << i2 << endl;
    }
};

int main()
{
    Display obj;

    obj.show(5);       // Calls show(int)
    obj.show(5.67);    // Calls show(double)
    obj.show("Hello"); // Calls show(const string&)
    obj.show(10, 20);  // Calls show(int, int)

    return 0;
}
