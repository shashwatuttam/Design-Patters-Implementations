#include<bits/stdc++.h>
using namespace std;

// Mediator class airport with single runway, i.e. mediator of flights of diff airlines
class Airport{
    queue< pair<int, string> > waiting_flights;
    int runway_occupied;
    pair<int, string> plane_on_runway;
public:
    Airport() { runway_occupied=0; }
    void land(int plane_id, string airline)
    {
        if(runway_occupied==0)
        {
            cout<<"Landing plane "<<plane_id<<" from "<<airline<<" on the runway!\n";
            runway_occupied = 1;
            plane_on_runway = {plane_id, airline};
        }
        else
        {
            cout<<"Runway occupied, added plane "<<plane_id<<" from "<<airline<<" to the waiting list\n";
            waiting_flights.push({plane_id, airline});
        }
    }

    void parkplane(int plane_id, string airline)
    {
        if(runway_occupied and plane_on_runway.first==plane_id)
        {
            cout<<"Moving plane "<<plane_id<<"("<<airline<<") from runway to hanger.\n";
            runway_occupied = 0;

            if(!waiting_flights.empty())
            {
                pair<int, string> temp = waiting_flights.front();
                waiting_flights.pop();
                cout<<"Landing waiting plane "<<temp.first<<" from airline "<<temp.second<<"\n";
                runway_occupied = 1;
                plane_on_runway = temp;
            }
        }
        else
        {
            cout<<"Plane "<<plane_id<<"("<<airline<<") is not present on runway!\n";
        }
    }
};

// Interface of airlines
class Airline{
protected:
    string name;
    Airport *airport;
public:
    Airline(string name, Airport *a) : name(name), airport(a) {}
    virtual void makeLandingReq(int plane_id) = 0;
    virtual void parkPlane(int plane_id) = 0;
};

// Airline 1 : Air India
class AirIndia : public Airline{
public:
    AirIndia(Airport *a) : Airline("Air India",a) {}
    
    void makeLandingReq(int plane_id)
    {
        airport->land(plane_id, name);
    }

    void parkPlane(int plane_id)
    {
        airport->parkplane(plane_id, name);
    }
};

// Airline 2 : Indigo
class Indigo : public Airline{
public:
    Indigo(Airport *a) : Airline("Indigo",a) {}
    
    void makeLandingReq(int plane_id)
    {
        airport->land(plane_id, name);
    }

    void parkPlane(int plane_id)
    {
        airport->parkplane(plane_id, name);
    }
};

int main()
{
    Airport IGIT3;

    Airline *air_india = new AirIndia(&IGIT3);
    Airline *indigo = new Indigo(&IGIT3);

    air_india->makeLandingReq(34);
    indigo->makeLandingReq(567);

    air_india->parkPlane(34);
    indigo->parkPlane(567);

    return 0;
}