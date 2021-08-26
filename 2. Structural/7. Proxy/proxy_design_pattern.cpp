#include<bits/stdc++.h>
using namespace std;

// Interface internet
class Internet{
public:
    virtual void connect(string url)=0;
};

// class for real internet
class RealInternet : public Internet{
public:
    void connect(string url)
    {
        cout<<"Connecting to "<<url<<"\n";
    }
};

// class for college internet blocking some websites
class CollegeInternet : public Internet{
    Internet *internet;
    unordered_set<string> banned_websites;
public:
    CollegeInternet()
    {
        internet = new RealInternet(); 
        vector<string> ban_list = {"abc.com", "def.com", "ijk.com", "lmo.com"};
        for(string i:ban_list)
        {
            banned_websites.insert(i);
        }
    }

    void connect(string url)
    {
        if(banned_websites.find(url)!=banned_websites.end())
        {
            cout<<"Access Denied\n";
        }
        else
        {
            internet->connect(url);
        }
    }
};

int main()
{
    CollegeInternet ci;
    ci.connect("google.com");
    ci.connect("abc.com");

    return 0;
}