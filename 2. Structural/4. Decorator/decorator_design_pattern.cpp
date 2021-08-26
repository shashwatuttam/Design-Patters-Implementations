#include<bits/stdc++.h>
using namespace std;

// Pizza interface
class Pizza{
public:
    virtual string getDescription() = 0;
    virtual int getCost() = 0;
};

// Base Pizza
class PizzaBase : public Pizza{
public:
    string getDescription()
    {
        return "This pizza contains : base";
    }
    int getCost()
    {
        return 69;
    }
};

// Decorator class
class ToppingDecorator : public Pizza{
protected:
    Pizza *my_pizza;
public:
    ToppingDecorator(Pizza *pizza) : my_pizza(pizza){}
    string getDescription() { return my_pizza->getDescription(); }
    int getCost() { return my_pizza->getCost(); }
};

// Cheese
class Cheese : public ToppingDecorator{
public:
    Cheese(Pizza *pizza) : ToppingDecorator(pizza){}
    string getDescription() { return my_pizza->getDescription() + ", cheese"; }
    int getCost() { return my_pizza->getCost() + 30; }
};

// Sauce
class Sauce : public ToppingDecorator{
public:
    Sauce(Pizza *pizza) : ToppingDecorator(pizza){}
    string getDescription() { return my_pizza->getDescription() + ", sauce"; }
    int getCost() { return my_pizza->getCost() + 20; }
};

// Onion
class Onion : public ToppingDecorator{
public:
    Onion(Pizza *pizza) : ToppingDecorator(pizza){}
    string getDescription() { return my_pizza->getDescription() + ", onion"; }
    int getCost() { return my_pizza->getCost() + 30; }
};

int main()
{
    Pizza *p1 = new Onion(new Cheese(new Sauce(new PizzaBase())));
    cout<<p1->getDescription()<<endl;
    cout<<p1->getCost()<<endl;

    Pizza *p2 = new PizzaBase();
    p2 = new Sauce(p2);
    p2 = new Cheese(p2);
    cout<<p2->getDescription()<<endl;
    cout<<p2->getCost()<<endl;

    return 0;
}