#include<bits/stdc++.h>
using namespace std;

// Drawing API interface
class DrawingAPI{
public:
    virtual string drawCircle(int x, int y, int r) const =0;
    virtual string drawSquare(int x, int y, int side) const=0;
};

// Drawing API 1 implements Drawing API interface
class DrawingAPI1 : public DrawingAPI{
public:
    string drawCircle(int x,int y, int r) const
    {
        return "API 1 : Drawing circle with center at ("+ to_string(x) + "," + to_string(y) +") and radius = "+ to_string(r) +"\n";
    }
    string drawSquare(int x, int y, int side) const
    {
        return "API 1 : Drawing square with left corner at ("+ to_string(x) + "," + to_string(y) +") and side = "+ to_string(side) +"\n";
    }
};

// Drawing API 2 implements Drawing API interface
class DrawingAPI2 : public DrawingAPI{
public:
    string drawCircle(int x,int y, int r) const
    {
        return "API 2 : Drawing circle with center at ("+ to_string(x) + "," + to_string(y) +") and radius = "+ to_string(r) +"\n";
    }
    string drawSquare(int x, int y, int side) const
    {
        return "API 2 : Drawing square with left corner at ("+ to_string(x) + "," + to_string(y) +") and side = "+ to_string(side) +"\n";
    }
};

// Shape abstract class
class Shape{
protected:
    const DrawingAPI &drawing_api;
public:
    Shape(const DrawingAPI &d) : drawing_api(d){}

    virtual void draw() = 0;
    virtual void resizeByPercentage(int) = 0;
};

// Circle extends Shape
class Circle : public Shape{
    int c_x, c_y, r;
public:
    Circle(int x, int y, int r, const DrawingAPI &d) : c_x(x), c_y(y), r(r), Shape(d){}

    void draw()
    {
        cout<<drawing_api.drawCircle(c_x,c_y,r);
    }

    void resizeByPercentage(int percent)
    {
        float p = (float)percent/100 + 1;
        r = r*p;
    }
};

// Square extends shape
class Square : public Shape{
    int tl_x, tl_y, side;
public:
    Square(int x, int y, int s, const DrawingAPI &d) : tl_x(x), tl_y(y), side(s), Shape(d){}

    void draw()
    {
        cout<<drawing_api.drawSquare(tl_x,tl_y,side);
    }

    void resizeByPercentage(int percent)
    {
        float p = (float)percent/100 + 1;
        side = side*p;
    }
};

int main()
{
    Circle c1(1,-1,10, DrawingAPI1());
    c1.draw();
    c1.resizeByPercentage(20);
    c1.draw();

    Square s1(3,3,100, DrawingAPI2());
    s1.draw();
    s1.resizeByPercentage(15);
    s1.draw();

    return 0;
}