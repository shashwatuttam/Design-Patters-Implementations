#include<bits/stdc++.h>
using namespace std;

// Interface for packings
class Packing{
public:
    virtual string getName()=0;
};

// PaperWrap implements packing
class PaperWrap : public Packing{
public:
    string getName(){ return "Paper Wrap"; }
};

// Bottle implements packing
class Bottle : public Packing{
public:
    string getName(){ return "Bottle"; }
};

// Interface for food items
class FoodItem{
public:
    virtual string getName()=0;
    virtual Packing* getPackaging()=0;
    virtual int getPrice()=0;
};

// Burger partially implements food item
class Burger:public FoodItem{
public:
    Packing* getPackaging()
    {
        return new PaperWrap();
    }
};

// Cold Drink partially implements food item
class ColdDrink:public FoodItem{
public:
    Packing* getPackaging()
    {
        return new Bottle();
    }
};

// Veg burger extends burger implementing some more methods from fooditem
class VegBurger:public Burger{
public:
    string getName() { return "Veg Burger"; }
    int getPrice() { return 99; }
};

// Non burger extends burger implementing some more methods from fooditem
class NonVegBurger:public Burger{
public:
    string getName() { return "Non-Veg Burger"; }
    int getPrice() { return 139; }
};

// Coke extends cold drink implementing some more methods from fooditem
class Coke:public ColdDrink{
public:
    string getName() { return "Coke"; }
    int getPrice() { return 49; }
};

// Coke extends cold drink implementing some more methods from fooditem
class Pepsi:public ColdDrink{
public:
    string getName() { return "Pepsi"; }
    int getPrice() { return 45; }
};

// Meal containing fooditems
class Meal{
private:
    string name;
    vector<FoodItem*> items;
    int cost=0;
public:
    void setName(string name){ this->name = name; }
    int getCost(){ return cost; }

    void addBurger(Burger* item)
    {
        items.push_back((FoodItem*)item); 
        cost+=item->getPrice();
    }

    void addDrink(ColdDrink* item)
    {
        items.push_back((FoodItem*)item); 
        cost+=item->getPrice();
    }

    void showDetails()
    {
        cout<<"Meal name : "<<name<<" : \n";
        for(int i=0; i<items.size(); i++)
        {
            cout<<"\t"<<items[i]->getName()<<" packed in a "<<(items[i]->getPackaging()->getName())<<", costs : Rs. "<<items[i]->getPrice()<<"\n";
        }
        cout<<"Amount : Rs. "<<cost<<"\n";
    }
};

// Meal builder to create different types of meals
class MealBuilder{
public:
    Meal createVegMeal()
    {
        Meal m1;
        m1.setName("Veg Meal");
        m1.addBurger(new VegBurger());
        m1.addDrink(new Coke());
        return m1;
    }

    Meal createNonVegMeal()
    {
        Meal m1;
        m1.setName("Non-veg meal");
        m1.addBurger(new NonVegBurger());
        m1.addDrink(new Pepsi());
        return m1;
    }
};


int main()
{
    MealBuilder mb;
    string mealtype;
    Meal my_meal;
    cout<<"Choose veg/non-veg (V/NV) : ";
    cin>>mealtype;
    if(mealtype=="V" or mealtype=="v")
    {
        my_meal = mb.createVegMeal();
    }
    else if(mealtype=="NV" or mealtype=="nv")
    {
        my_meal = mb.createNonVegMeal();
    }
    else
    {
        cout<<"Invalid choice entered, exiting!";
        return 0;
    }

    cout<<"Your meal details are:\n";
    my_meal.showDetails();
    return 0;
}