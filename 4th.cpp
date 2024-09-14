#include <iostream>
#include <cstring>
using namespace std;
class Hero
{
    // properties
private:
    char n[100]; // 100byte
public:
    char *name;
    int health; // 4byte
    char level; // 1byte

    Hero() // default constructor
    {
        cout << "simple constructor called" << endl;
        name = new char[100];
    }

    // parameterized constructor
    Hero(int health)
    {
        cout << "contructor called 1" << endl;
        this->health = health;
        // this keyword is the pointer to the current object
    }
    Hero(int health, char level)
    {
        cout << "contructor called 2" << endl;
        this->health = health;
        this->level = level;
        // this is the pointer to the current object
    }

    // copy constructor
    Hero(Hero &temp) // passing by reference for avoiding infinite loop
    {
        cout << "copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void setLevel(int level)
    {
        this->level = level;
    }
    void setName(char name)
    {
        cout << name << endl;
    }
    void print()
    {
        cout << "name " << this->name << endl;
        cout << "health " << this->health << endl;
        cout << "level " << this->level << endl;
    }
    void setHealth(int h)
    {
        health = h;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }
};
int main()
{
    Hero suresh(70, 'B');
    suresh.print();

    // copy constructor
    Hero ritesh(suresh);
    // ritesh.health = suresh.health;
    // ritesh.level = suresh.level;
    ritesh.print();

    // default copy constructor is shallow copy
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('S');

    char name[7] = "dev";
    hero1.setName(name);

    hero1.print();

    return 0;
}