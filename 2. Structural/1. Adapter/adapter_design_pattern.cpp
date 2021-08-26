/* Used to connect two classes having non compatiple APIs
Here we are using adapter pattern to charge an Iphone using USB C Charger */

#include<bits/stdc++.h>
using namespace std;

class UsbCPhone{
public:
    virtual void connectUsbC()=0;
    virtual void charge()=0;
};

class LightningPhone{
public:
    virtual void connectLightning()=0;
    virtual void charge()=0;
};

class Android : public UsbCPhone{
    int connected=0;
public:
    void connectUsbC()
    {
        connected = true;
        cout<<"Charging cable connected in USB C Port\n";
    }

    void charge()
    {
        if(connected)
        {
            cout<<"Charging!\n";
        }
        else 
        { 
            cout<<"Connect USB C Cable first!!\n"; 
        }
    }
};

class IPhone : public LightningPhone{
    int connected = 0;
public:
    void connectLightning()
    {
        connected = true;
        cout<<"Charging cable connected in Lightning Port\n";
    }

    void charge()
    {
        if(connected)
        {
            cout<<"Charging!\n";
        }
        else 
        { 
            cout<<"Connect Lightning Cable first!!\n"; 
        }
    }
};

class UsbCtoLightningAdapter : public UsbCPhone{
    LightningPhone *targetPhone;
public:
    UsbCtoLightningAdapter(LightningPhone *targetPhone)
    {
        this->targetPhone = targetPhone;
    }

    void connectUsbC()
    {
        cout<<"USB C -> (usb) adapter (lightning) -> iphone\n";
        targetPhone->connectLightning();
    }

    void charge()
    {
        cout<<"Charge request using adapter!\n";
        targetPhone->charge();
    }
};

void chargeUsbCPhone(UsbCPhone *phone)
{
    phone->connectUsbC();
    phone->charge();
}

int main()
{
    UsbCPhone *oneplus7t = new Android();
    LightningPhone *iphonex = new IPhone();

    cout<<"Lets charge Oneplus 7T using USB C Charger\n";
    chargeUsbCPhone(oneplus7t);

    cout<<"Lets charge Iphone X using USB C Charger\n";
    chargeUsbCPhone(new UsbCtoLightningAdapter(iphonex));

    return 0;
}