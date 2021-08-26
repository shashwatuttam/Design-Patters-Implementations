#include<bits/stdc++.h>
using namespace std;

// Stock class
class Stock{
    string name;
    int quantity_to_trade;
public:
    Stock(string name, int quantity) : name(name), quantity_to_trade(quantity) {}

    virtual void buyStock()
    {
        cout<<"Bought "<<quantity_to_trade<<" units of stock : "<<name<<"\n";
    }

    virtual void sellStock()
    {
        cout<<"Sold "<<quantity_to_trade<<" units of stock : "<<name<<"\n";
    }
};

// order interface
class Order{
public:
    virtual void execute() = 0;
};

// buyorder implemenrs order
class BuyOrder : public Order{
    Stock *stock;
public:
    BuyOrder(Stock *s) : stock(s){}
    void execute()
    {
        stock->buyStock();
    }
};

// sell order implements order
class SellOrder : public Order{
    Stock *stock;
public:
    SellOrder(Stock *s) : stock(s){}
    void execute()
    {
        stock->sellStock();
    }
};

// Broker executing commands
class Broker{
    vector<Order*> orders;
public:
    void takeOrder(Order *order)
    {
        orders.push_back(order);
    }

    void executeOrders()
    {
        for(Order *order:orders)
        {
            order->execute();
        }
    }
};

int main()
{
    Broker zerodha;

    //define stock
    Stock s1("QCOM",50);

    //place buy order
    BuyOrder bo(&s1);
    zerodha.takeOrder(&bo);
    
    //place sell order
    SellOrder so(&s1);
    zerodha.takeOrder(&so);

    //execute orders
    zerodha.executeOrders();

    return 0;
}