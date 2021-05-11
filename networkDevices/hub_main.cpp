#include<bits/stdc++.h>
#include "line_encoding1.h"
#include "topology.h"
using namespace std;

struct end_devices
{
    string ip_address;
    string address;
    string data;
    void recieve(string a,int *data)
    {
        if(address==a || a=="FF:FF:FF:FF:FF:FF")
        {
            cout<<"data received at: " <<address<<endl;

        }
        else
        {
            cout<<"data rejected by: "<<address<<endl;
        }
        // delay(1000);
    }
};
struct hub
{
    string address;
    string ip_address;
    end_devices ed[5];
    void send(string add_s,string add_r,int* data)
    {
        for(int i=0;i<5;i++)
         {
             if(ed[i].address!="add_s")
             ed[i].recieve(add_r,data);
         }
    }
    void recieve(string add_s,string add_r,int* data)
    {
        cout<<endl;
        cout<<"data received at hub send by the device: "<<add_s<<endl;
        cout<<endl;
        cout<<"broadcasting data to all devices"<<endl;
        cout<<endl;
        this->send(add_s,add_r,data);
    }

};
struct network
{
    hub h;

    network()
    {
    h.address="AA:AA:AA:EH:0D:AA";
    h.ed[0].address="AA:AA:AA:44:A0:AB";
    h.ed[1].address="AA:AA:AA:11:0E:AC";
    h.ed[2].address="AA:00:1B:AA:AA:AD";
    h.ed[3].address="B0:11:AA:AA:AA:AE";
    h.ed[4].address="AA:E1:33:AA:AA:AF";

    cout<<"following are the devices connected to network:-"<<endl;
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<i+1<<" . "<<h.ed[i].address<<endl;
    }
    cout<<endl;

    delay(1000);
    topology();
}

    void send_data()
    {
        cout<<"enter senders address"<<endl;
        string add_s;
        cin>>add_s;
        cout<<"enter receiver's address"<<endl;
        string add_r;
        cin>>add_r;
        cout<<endl;
        cout<<"enter data to send"<<endl;
        int* data=encode();

         h.recieve(add_s,add_r,data);
         cout<<endl;
    }

    void broadcast()
    {
         cout<<"enter data to broadcast"<<endl;
        int* data=encode();
        cout<<endl;
        for(int i=0;i<5;i++)
        {
            h.ed[i].recieve("FF:FF:FF:FF:FF:FF",data);
        }
    }
};



void hub_main()
{
   network n;
   cout<<"enter your choices:" <<endl;
     int s;
    cout<<"select from following :- "<<endl;
    cout<<"1- Send data"<<endl;
    cout<<"2- Broadcast data"<<endl;
    cin>>s;
    switch(s)
    {

    case 1:
        {
            n.send_data();
            break;
        }
    case 2:
        {
            n.broadcast();
            break;
        }
    }
}
