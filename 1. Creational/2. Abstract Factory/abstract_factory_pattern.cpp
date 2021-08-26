/* SImilar to factory design pattern, 
but here we group the objects into families,
and have a separate factory for each family */
   
#include<bits/stdc++.h>
using namespace std;

// Types of builders, shapes and colors
enum builderType{
    DEFAULT_SHAPE_BUILDER=0, ROUNDED_SHAPE_BUILDER
};

// Interface class Shape
class Shape{
public:    
    virtual void myShape()=0;
};

// Square implements shape
class Square : public Shape{
public:
    void myShape()
    {
        cout<<"Default Square is the shape that is made.\n";
    }
};

// Rectangle implements shape
class Rectangle : public Shape{
public:
    void myShape()
    {
        cout<<"Default Rectangle is the shape that is made.\n";
    }
};

// Rounded Square implements shape
class RoundedSquare : public Shape{
public:
    void myShape()
    {
        cout<<"Rounded Square is the shape that is made.\n";
    }
};

// Rounded Rectangle implements shape
class RoundedRectangle : public Shape{
public:
    void myShape()
    {
        cout<<"Rounded Rectangle is the shape that is made.\n";
    }
};

class AbstractFactory{
public:
    virtual Shape* getShapeObj(string)=0;

    static AbstractFactory* getBuilderObj(builderType b_type);
};

// Shape factory class that returns a shape based on the type passed.
class DefaultShapeFactory : public AbstractFactory{
public:
    Shape* getShapeObj(string s_type)
    {
        if(s_type=="Square" or s_type=="S")
            return new Square();
        else if(s_type=="Rectangle" or s_type=="R")
            return new Rectangle();
        else
        {
            cout<<"Given shape is not available as deafault!\n";
            return NULL;
        }
    }
};

// Shape factory class that returns a shape based on the type passed.
class RoundedShapeFactory : public AbstractFactory{
public:
    Shape* getShapeObj(string s_type)
    {
        if(s_type=="Rounded Square" or s_type=="RS")
            return new RoundedSquare();
        else if(s_type=="Rounded Rectangle" or s_type=="RR")
            return new RoundedRectangle();
        else
        {
            cout<<"Given shape is not available as rounded!\n";
            return NULL;
        }
    }
};

AbstractFactory* AbstractFactory::getBuilderObj(builderType b_type)
{
    switch(b_type)
    {
        case DEFAULT_SHAPE_BUILDER : return new DefaultShapeFactory();
        case ROUNDED_SHAPE_BUILDER : return new RoundedShapeFactory();
        default : return NULL;
    }
}

int main()
{
    int fam_type;
    string s_type;
    cout<<"Enter the shape family required (0:Default shapes, 1:Rounded Shapes)";
    cin>>fam_type;
    cout<<"Enter the shape required ";
    if(fam_type==DEFAULT_SHAPE_BUILDER)
    {
        cout<<"Square/Rectangle (S/R)\n";
    }
    else if(fam_type==ROUNDED_SHAPE_BUILDER)
    {
        cout<<"Rounded Square/Rounded Rectangle (RS/RR)\n";
    }
    else
    {
        cout<<"Wrong family entered, exiting!\n";
        return 0;
    }
    cin>>s_type;

    AbstractFactory *sf1 = AbstractFactory::getBuilderObj((builderType)fam_type);
    Shape* s = sf1->getShapeObj(s_type);
    
    if(s)
    {
        s->myShape();
    }
    else
    {
        cout<<"Wrong choices entered!";
    }
}