#include <iostream>
using namespace std;
class A
{
    int x;

public:
    A &setData(int x)
    {
        this->x = x;
        return *this;
    }
    // void setData(int a){
    //     this->a = a;
    // }

    void getData()
    {
        cout << "The value of x is " << x << endl;
    }
};

int main()
{
    A obj;
    obj.setData(4);

    obj.getData();
    return 0;
}
