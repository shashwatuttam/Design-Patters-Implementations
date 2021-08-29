#include<bits/stdc++.h>
using namespace std;

// The observer abstract class
class Observer{
protected:
    string name;
public:
    Observer(string name) : name(name) {}
    virtual void update(string) = 0;
};

// The subject class i.e. publisher
class Publisher{
    list<Observer*> subscribers;
public:
    void registerUser(Observer *o)
    {
        subscribers.push_back(o);
    }

    void deRegisterUser(Observer *o)
    {
        subscribers.remove(o);
    }

    void notifyObservers(string update_msg)
    {
        for(Observer*i : subscribers)
        {
            i->update(update_msg);
        }
    }
};

// Observers type 1 : Reviewers
class Reviewer : public Observer{
public:
    Reviewer(string name, Publisher *p) : Observer(name) { p->registerUser(this); }

    void update(string msg)
    {
        cout<<"Update published to reviewer "<<name<<" : "<<msg<<"\n";
    }
};

// Observers type 2 : Reviewers
class Customer : public Observer{
public:
    Customer(string name, Publisher *p) : Observer(name) { p->registerUser(this); }

    void update(string msg)
    {
        cout<<"Update published to customer "<<name<<" : "<<msg<<"\n";
    }
};

int main()
{
    Publisher google_Pixel;

    Reviewer mkbhd("MKBHD", &google_Pixel);
    Reviewer mrMobile("Mr Mobile",&google_Pixel);

    Customer shashwat("Shashwat",&google_Pixel);
    Customer gamer("OneUnknownGamer",&google_Pixel);

    google_Pixel.notifyObservers("Google Pixel 5A has been released!");
    google_Pixel.deRegisterUser(&gamer);
    google_Pixel.deRegisterUser(&mrMobile);

    google_Pixel.notifyObservers("Google Pixel 6 will be released with Tensor Chip!");
    return 0;
}