#include <iostream>
using namespace std;
class Hero
{
    // properties
public:
    char name[100]; // 100byte
    int health;     // 4byte
    char level;     // 1byte
};
int main()
{
    // creation of object
    Hero h1;
    // In case of empty class (no properties) , 1 byte memory is allocated
    cout << "size :" << sizeof(h1) << endl; // its giving size of 108  because of padding and greedy alignment

    // below code will give error if health and level is not public()
    // access modifiers -> (i)public
    //                     (ii)private->(by default),can be accesessed within the class
    //                     (iii)protected->

    h1.health = 70;
    h1.level = 'a';
    cout << "health :" << h1.health << endl;
    cout << "level :" << h1.level << endl;

    return 0;
}