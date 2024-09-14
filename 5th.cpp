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
    static int timeToComplete;

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

    static int random()
    {
        return timeToComplete;
    }
    // Destructor
    ~Hero()
    {
        cout << "destructor called" << endl;
    }
};

int Hero ::timeToComplete = 5;
int main()
{
    // destractor
    //(i)no return type
    //(ii)no input parameter

    // static -> destructor automatically called
    Hero a;

    // Dynamic -> manually destructor call
    Hero *b = new Hero();
    delete b;

    // static -- belong to class (doesnot belong to object) data member->access
    cout << Hero::timeToComplete << endl;
    cout << Hero::random() << endl;

    // static function
    // no need to create object
    //  this keyword not available ( no object no this object)//this keywork is pointer to current object
    // static object can access static member only
    return 0;
}