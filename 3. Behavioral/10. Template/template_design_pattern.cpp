#include<bits/stdc++.h>
using namespace std;

// Momo abstract class with template
class Momo{
public:
    const void makeMomo()
    {
        prepareDough();
        makeOuterLayer();
        addChicken();
        addVeggies();
        addCheese();
        addCondiments();
        steam();
    }

    void prepareDough() { cout<<"Preparing dough!\n"; }
    void makeOuterLayer() { cout<<"Making outer layer!\n"; }
    void steam() { cout<<"Away to the steamer!\n"; }

    virtual void addChicken() = 0;
    virtual void addVeggies() = 0;
    virtual void addCheese() = 0;
    virtual void addCondiments() = 0;
};

// sub class veg momo
class VeganMomo : public Momo{
private:
    vector<string> veggies = {"cabbage", "carrot", "onion"};
    vector<string> condiments = {"garlic","ginger","oil"};
public:
    void addChicken(){}
    
    void addVeggies()
    {
        cout<<"Adding veggies : ";
        for(string veggie:veggies)
        {
            cout<<veggie<<" ";
        }
        cout<<"\n";
    }

    void addCheese()
    {
        cout<<"Adding vegan cheese\n";
    }

    void addCondiments()
    {
        cout<<"Adding condiments : ";
        for(string condiment : condiments)
        {
            cout<<condiment<<" ";
        }
        cout<<"\n";
    }
};

// sub class veg momo
class ChickenMomo : public Momo{
private:
    vector<string> condiments = {"salt","pepper","oil"};
public:
    void addChicken()
    {
        cout<<"Adding chicken!\n";
    }
    
    void addVeggies(){}

    void addCheese()
    {
        cout<<"Adding regular cheese\n";
    }

    void addCondiments()
    {
        cout<<"Adding condiments : ";
        for(string condiment : condiments)
        {
            cout<<condiment<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    Momo *vegan_momo = new VeganMomo();
    cout<<"Making vegan momo\n";
    vegan_momo->makeMomo();

    Momo *chicken_momo = new ChickenMomo();
    cout<<"\nMaking chicken momo\n";
    chicken_momo->makeMomo();
    return 0;
}