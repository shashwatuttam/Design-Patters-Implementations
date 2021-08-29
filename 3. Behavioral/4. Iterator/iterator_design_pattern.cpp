#include<bits/stdc++.h>
using namespace std;

// Notification class
class Notification{
    string message;
public:
    Notification(){ message=""; }
    Notification(string s) : message(s) {}

    string getMessage(){ return message; }
};

// Iterator for notifications
class NotificationIterator{
    Notification *notification_list;
    int size, position;
public:
    NotificationIterator(Notification *g, int size, int p=0) : notification_list(g), size(size), position(p) {}

    bool hasNext()
    {
        return (position < size);
    }

    Notification* getNext()
    {
        if(position < size)
        {
            return &notification_list[position++];
        }
        else
            return NULL;
    }
};

// Collection of notifications with a get_iterator method
class NotificationGroup{
    int capacity, size;
    Notification *notifications;
public:
    NotificationGroup()
    {
        capacity = 10; size = 0;
        notifications = new Notification[capacity];
    }
    void add(Notification n)
    {
        if(size<=capacity)
        {
            notifications[size] = n;
            size++;
        }
        else
        {
            cout<<"Notifications group is full!\n";
        }
    }
    void clearAll(){ size = 0; }

    NotificationIterator* getIterator()
    {
        return new NotificationIterator(notifications, size);
    }
};

int main()
{
    NotificationGroup *email_notifs = new NotificationGroup();

    email_notifs->add(Notification("Someone sent you a friend request!"));
    email_notifs->add(Notification("Amazon big billion days incoming!!"));
    email_notifs->add(Notification("Shashwat, your daily news digest"));

    NotificationIterator *it = email_notifs->getIterator();
    while(it->hasNext())
    {
        cout<< it->getNext()->getMessage()<<"\n";
    }

    return 0;
}