#include <iostream>
using namespace std;
class Hero
{
    // properties
private:
    char name[100]; // 100byte
public:
    int health; // 4byte
    char level; // 1byte

    char setName(char n)
    {
        return n;
    }
};
int main()
{
    // static allocation
    Hero a;
    cout << a.setName('h') << endl;
    cout << a.level << endl;
    cout << a.health << endl;

    // dynamic allocation( memory allocated in heap)
    Hero *b = new Hero;          // b -> address
    cout << (*b).health << endl; // this is correct
    cout << b->level << endl;    // this is also correct

    return 0;
}