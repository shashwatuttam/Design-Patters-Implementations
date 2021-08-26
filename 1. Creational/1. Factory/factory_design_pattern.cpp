/* Design pattern where a function returns one of several possible
   class objects that share the same base class */
   
#include<bits/stdc++.h>
using namespace std;

enum shapeType{
    CIRCLE=0,SQUARE,RECTANGLE
};

// Interface class Shape
class Shape{
public:    
    virtual void myShape()=0;
};

// Circle implementing shape
class Circle : public Shape{
public:
    void myShape()
    {
        cout<<"Circle is the shape that is made.\n";
    }
};

// Square implements shape
class Square : public Shape{
public:
    void myShape()
    {
        cout<<"Square is the shape that is made.\n";
    }
};

// Rectangle implements shape
class Rectangle : public Shape{
public:
    void myShape()
    {
        cout<<"Rectangle is the shape that is made.\n";
    }
};

// Object factory class that returns object based on the type passed.
class ObjectFactory{
public:
    Shape* getObject(shapeType obj_type)
    {
        switch (obj_type)
        {
            case CIRCLE:
                return new Circle();

            case SQUARE:
                return new Square();

            case RECTANGLE:
                return new Rectangle();

            default:
                return NULL;
        }
    }
};

int main()
{
    int type;
    cout<<"Enter the type of object required (0:Circle, 1:Square, 2:Rectangle)";
    cin>>type;

    ObjectFactory of;
    Shape *obj1 = of.getObject((shapeType)type);
    if(obj1!=NULL)
    {
        obj1->myShape();
    }
    else
    {
        cout<<"Wrong object type!";
    }
}