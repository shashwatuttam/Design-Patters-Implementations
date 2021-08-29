#include<bits/stdc++.h>
using namespace std;

// Memento class : unit of data to be stored
class Memento{
    string data;
public:
    Memento(string data) : data(data) {}
    string getData() { return data; }
};

// Caretaker class to maintain saved states and retrieve them
class CareTaker{
    vector<Memento*> history;
public:
    void saveState(Memento* m)
    {
        cout<<"Saving "<<m->getData()<<" , in state "<<history.size()<<"\n";
        history.push_back(m);
    }

    Memento* getState(int state)
    {
        if(state<history.size())
            return history[state];
        else
        {
            cout<<"Invalid state entered, returning NULL!\n";
            return NULL;
        }
    }
};

// Originator class to handle the operations
class Originator{
    string data;
public:
    Originator(string data) : data(data) {}

    void setData(string data)
    {
        cout<<"Changing data from "<<this->data<<" , to "<<data<<"\n";
        this->data = data;
    }

    Memento* createMemento()
    {
        return new Memento(data);
    }

    void restoreMemento(Memento *m)
    {
        data = m->getData();
    }

    void showData()
    {
        cout<<data<<"\n";
    }
};

int main()
{
    Originator o1("This is the initial text!");
    CareTaker c1;

    o1.setData("v2 : Changed some data.");
    c1.saveState(o1.createMemento());

    o1.setData("v3 : Feel the change!");
    c1.saveState(o1.createMemento());

    cout<<"Restoring to state 0\n";
    o1.restoreMemento(c1.getState(0));
    o1.showData();

    cout<<"Restoring to state 1\n";
    o1.restoreMemento(c1.getState(1));
    o1.showData();
    return 0;
}