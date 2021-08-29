/* Select flying strategy(Flying/can't fly) based on the animal (passed param in this case) */

#include<bits/stdc++.h>
using namespace std;

// Startegy interface, i.e. flying
class Flys{
public:
    virtual void fly()=0;
};

// Strategy 1 : Fly
class CanFly : public Flys{
public:
    void fly() { cout<<"I'm flying\n"; }
};

// Strategy 2 : Can't Fly
class CantFly : public Flys{
public:
    void fly() { cout<<"I can't fly :(\n"; }
};

// Context class
class Animal{
protected:
    string name;
    Flys *flys;
public:
    Animal(string name, bool canFly) : name(name)
    {
        if(canFly) flys = new CanFly();
        else flys = new CantFly();
    }

    void tryToFly()
    {
        cout<<"Hi I'm a "<<name<<". ";
        flys->fly();
    }
};

int main()
{
    Animal a1("Dog", 0);
    Animal a2("Pigeon", 1);
    Animal a3("Fish", 0);

    a1.tryToFly();
    a2.tryToFly();
    a3.tryToFly();
    return 0;
}