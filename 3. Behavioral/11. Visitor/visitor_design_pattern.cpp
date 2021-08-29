/*
Used when a visitor wants to apply same operation in different ways on different classes
Here tax visitor applies tax on Liquorm Tobacco, Necessities with differents rates

Visitor <-- TaxVisitor  (provides visit method to apply operation on objects)
Visitable <-- Liquor,Tobacco,Necessities (provides accept method to accept visitor)
*/

#include<bits/stdc++.h>
using namespace std;

// Early declaration for compilation reasons
class Liquor;
class Tobacco;
class Necessity;

// Visitor interface
class Visitor{
public:
    virtual float visit(Liquor *liquor) = 0;
    virtual float visit(Tobacco *tobacco) = 0;
    virtual float visit(Necessity *necessity) = 0;
};

// Items that we want to perform operations on / visit
class Visitable{
public:
    virtual float accept(Visitor *visitor) = 0;
};

// Item 1
class Liquor : public Visitable{
    float price;
public:
    Liquor(float price) : price(price) {}
    float getPrice() { return price; }

    float accept(Visitor *visitor)
    {
        return visitor->visit(this);
    }
};

// Item 2
class Tobacco : public Visitable{
    float price;
public:
    Tobacco(float price) : price(price) {}
    float getPrice() { return price; }
    
    float accept(Visitor *visitor)
    {
        return visitor->visit(this);
    }
};

// Item 3
class Necessity : public Visitable{
    float price;
public:
    Necessity(float price) : price(price) {}
    float getPrice() { return price; }

    float accept(Visitor *visitor)
    {
        return visitor->visit(this);
    }
};

// TaxVisitor is a visitor to visit above items and apply tax rate according to type of item
class TaxVisitor : public Visitor{
public:
    float visit(Liquor *liquor)
    {
        cout<<"Liquor Item - Price with tax : ";
        return liquor->getPrice()*1.18;
    }

    float visit(Tobacco *tobacco)
    {
        cout<<"Tobacco Item - Price with tax : ";
        return tobacco->getPrice()*1.28;
    }
    
    float visit(Necessity *necessity)
    {
        cout<<"Necessity Item - Price with tax : ";
        return necessity->getPrice()*1.08;
    }   
};

int main()
{
    Necessity rice(50);
    Liquor corona(300);
    Tobacco itc(150);

    Visitor *tax_visitor = new TaxVisitor();
    cout<<rice.accept(tax_visitor)<<"\n";
    cout<<corona.accept(tax_visitor)<<"\n";
    cout<<itc.accept(tax_visitor)<<"\n";
    return 0;
}