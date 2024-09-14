// protected is similar to private ,
// Only difference is that is may be accessed in child class

#include <iostream>
using namespace std;
class Human
{
public:
    int weight;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
    void setWeight(int weight)
    {
        this->weight = weight;
    }
};
class Male : public Human
{
public:
    string color;

    void sleep()
    {
        cout << "male sleeping" << endl;
    }
};
int main()
{
    // ? first;
    Male male1;
    male1.sleep();
    cout << male1.age << endl;
    cout << male1.height << endl;
    cout << male1.color << endl;
    male1.setWeight(30);
    cout << male1.weight << endl;
    return 0;
}