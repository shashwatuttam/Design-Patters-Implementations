#include<bits/stdc++.h>
using namespace std;

class Car{
private:
    string name;
    string color;
public:
    Car(string name, string color) : name(name), color(color){};
    
    void setColor(string color){ this->color = color; }
    void setName(string name){ this->name = name; }

    virtual Car* clone() = 0;

    virtual void showDetails(){
        cout<<"Car name : "<<name<<", color : "<<color<<"\n";
    }
};

class RaceCar : public Car{
public:
    int max_speed;
public:
    RaceCar(string name, string color, int maxSpeed): Car(name,color),max_speed(maxSpeed){}

    Car* clone()
    {
        return new RaceCar(*this);
    }
};

class Pickup : public Car{
private:
    int tow_capacity;
public:
    Pickup(string name, string color, int tow_cap) : Car(name,color), tow_capacity(tow_cap){}

    Car* clone()
    {
        return new Pickup(*this);
    }
};

int main()
{
    vector<Car*> cars;

    Car *lambo_prototype = new RaceCar("lambo","",300);
    Car *ford_prototype = new Pickup("ford f1", "", 11000);
    
    Car *c1 = lambo_prototype->clone();
    c1->setColor("Red");
    cars.push_back(c1);

    c1 = ford_prototype->clone();
    c1->setColor("Grey");
    cars.push_back(c1);

    lambo_prototype->showDetails();
    ford_prototype->showDetails();
    cars[0]->showDetails();
    cars[1]->showDetails();
    return 0;
}