// wrapping up data members and functions
// information hiding
// capsule -> class
// class -> data members
//      -> functions

// fully encapsulated class -> all data members are private
// advantage -> data hide,security,we can make class read only,code reusibility

#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int age;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
};
int main()
{
    Student first;

    return 0;
}