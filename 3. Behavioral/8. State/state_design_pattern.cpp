/* Ideally state pattern would have states changing each others state rather tham the user
    but made this for a simple example */

#include<bits/stdc++.h>
using namespace std;

// State Interface
class State{
protected:
    string name;
public:
    State(string name) : name(name) {}
    virtual void handleAlert() = 0;
    string getName() { return name; }
};

// Context class i.e. phone
class Phone{
    State *state;
public:
    void setState(State *s)
    {
        cout<<"Setting phone state to "<<s->getName()<<"\n";
        state = s;
    }
    void alert()
    {
        state->handleAlert();
    }
};

// State type : Ringer
class RingerState : public State{
public:
    RingerState() : State("Ringer") {}
    void handleAlert()
    {
        cout<<"Trnnnngggggggg.......\n";
    }
};

// State 2 : Vibrate
class VibrateState : public State{
public:
    VibrateState() : State("Vibrate") {}
    void handleAlert()
    {
        cout<<"Buzzzzzzzzzzzz......\n";
    }
};

// State 3 : Silent
class SilentState : public State{
public:
    SilentState() : State("Silent") {}
    void handleAlert()
    {
        cout<<"Light up display.\n";
    }
};

int main()
{
    Phone p;
    p.setState(new RingerState());
    p.alert();
    p.alert();

    p.setState(new SilentState());
    p.alert();

    p.setState(new VibrateState());
    p.alert();
    p.alert();
    p.alert();

    return 0;
}