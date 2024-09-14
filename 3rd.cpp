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

    // parameterized constructor
    Hero(int health)
    {
        cout << "contructor called" << endl;
        this->health = health;
        // this is the pointer to the current object
    }

    void setName(char name)
    {
        cout << name << endl;
    }
};
int main()
{
    // constructor
    //(i)Object creation invoke
    //(i)NO return type

    // if we difine our own constructor then the system constructor will vanish

    // statically
    // Hero ramesh; // it will automatically call ramesh.Hero() even if we haven't defined Hero inside it
    // dynamically
    // Hero *h = new Hero();

    // Parameterized constructor
    Hero ramesh(10);
    cout << ramesh.health << endl;
    Hero *h = new Hero(15);
    cout << (h)->health << endl;

    return 0;
}