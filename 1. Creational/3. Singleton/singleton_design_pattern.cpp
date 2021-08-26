#include<bits/stdc++.h>
using namespace std;

class Singleton{
private:
    //value that is to have single instance, 
    //since this is non static, and only 1 object is there, it will have only 1 copy
    int cell;  

    Singleton(){ cell=100; };   //private constructor
    Singleton(Singleton& o1);   //remove default copy constructor
    void operator=(Singleton);  //remove default = operator
public:
    static Singleton& getInstance()
    {
        static Singleton instance;  //single object
        return instance;
    }

    //getter & setters
    int getCell(){ return cell; }
    void setCell(int cell){ this->cell = cell; }
};

int main()
{
    Singleton &a = Singleton::getInstance();
    cout<<a.getCell()<<"\n";
    a.setCell(50);
    cout<<a.getCell();
    return 0;
}