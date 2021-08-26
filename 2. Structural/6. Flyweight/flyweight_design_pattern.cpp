#include<bits/stdc++.h>
using namespace std;

enum color_options{
    RED=0, GREEN, BLUE, BLACK, WHITE, MAX_COLOR
};

// Class circle
class Circle{
    int cx,cy,radius,color;
public:
    Circle(int cx, int cy, int radius, int color): cx(cx), cy(cy), radius(radius), color(color) {}

    //setters for non cached params
    void setCenter(int cx, int cy)
    {
        this->cx = cx;
        this->cy = cy;
    }

    void setRadius(int r) { radius = r; }

    void draw()
    {
        cout<<"Circle at ("<<cx<<", "<<cy<<") with radius "<<radius<<" and color "<<(color_options)color<<"\n";
    }
};

// Circle Factory for returning cached/new objects
class CircleFactory{
    unordered_map<int, Circle*> cache;
public:
    Circle* getCircle(int cx, int cy, int radius, int color)
    {
        Circle *res;

        //return after setting new values, if found in cache
        if(cache.find(color)!=cache.end())
        {
            res = cache[color];
            res->setCenter(cx,cy);
            res->setRadius(radius);
        }
        //create new object if not found in cache
        else
        {
            res = new Circle(cx,cy,radius,color);
            cache[color] = res;
            cout<<"Created new circle for color "<<color<<"\n";
        }
        return res;
    }

};

int main()
{
    //set random seed using current time
    srand(time(0));

    int x,y,r,color;
    CircleFactory cf;
    for(int i=0; i<50; i++)
    {
        x = rand(); y=rand(); r=rand();  //random
        color = rand()%MAX_COLOR;        //random from 0 to Max no of colors

        Circle *temp = cf.getCircle(x,y,r,color);
        temp->draw();
    }

    return 0;
}