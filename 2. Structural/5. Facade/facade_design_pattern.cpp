#include<bits/stdc++.h>
using namespace std;

// Class describing a bank account
class BankAccount{
    int accountNo, securityPIN, balance, debitCardNum;
    string name;

    //hidden internal working
    bool checkCardNumber(int cardNum) { return cardNum==debitCardNum?1:0; }

    bool checkSecurityPIN(int securityPIN) { return securityPIN==this->securityPIN?1:0; } 

    bool checkAvailBal(int required) { return required<=balance?1:0; }
public:
    BankAccount(int accNo, string name, int debitCardNum, int pin) : accountNo(accNo), name(name), securityPIN(pin), debitCardNum(debitCardNum), balance(0)
    {
        cout<<"Hi "<<name<<", welcome to the bank\n";
    }

    //exposed functions to client : update pin, withdraw and deposit
    void updateSecurityPIN(int currentPIN, int newPIN)
    {
        if(currentPIN == securityPIN)
            securityPIN = newPIN;
        else
            cout<<"Current PIN is incorrect!\n";

    }

    void withdrawCash(int cardNumber, int amount, int securityPIN)
    {
        if(checkCardNumber(cardNumber) && checkSecurityPIN(securityPIN) && checkAvailBal(amount))
        {
            balance-=amount;
            cout<<"Collect Rs. "<<amount<<" from the tray!\nAvail bal : "<<balance<<"\n";
        }
        else
        {
            cout<<"Transaction Failed\n";
        }
    }

    void depositCash(int cardNumber, int amount, int securityPIN)
    {
        if(checkCardNumber(cardNumber) && checkSecurityPIN(securityPIN))
        {
            balance+=amount;
            cout<<"Rs. "<<amount<<" credited into the account!\nAvail bal : "<<balance<<"\n";
        }
        else
        {
            cout<<"Transaction Failed!\n";
        }
    }
};


int main()
{
    BankAccount my_account(1234, "Shashwat Uttam", 4321, 9999);
    my_account.depositCash(4321, 1000, 1111);  //wrong PIN, fail
    my_account.withdrawCash(4321, 500, 9999);  //balance not enough, fail
    my_account.depositCash(4321, 1000, 9999);  //deposit
    my_account.withdrawCash(4321, 500, 9999);  //withdraw
    return 0;
}