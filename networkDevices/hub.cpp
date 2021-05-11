#include<bits/stdc++.h>
using namespace std;

class Hub {
    long long int ipAdress;
    long long int macAddress;
    vector<long long int> connections;  //contain end devices no. which are connected to it 
};

struct end_devices
{
    string ip_address;
    string address;
    string data;
    void recieve(string a)
    {
        if(address==a || a=="FF:FF:FF:FF")
        {
            cout<<"data received at: " <<address<<endl;
        }
        else
        {
            cout<<"data rejected by: "<<address<<endl;
        }
    }
};
struct hub
{
    string address;
    string ip_address;
    end_devices ed[5];
    void send(string add_s,string add_r,string data)
    {
        for(int i=0;i<5;i++)
         {
             if(ed[i].address!="add_s")
             ed[i].recieve(add_r);
         }
    }
    void recieve(string add_s,string add_r,string data)
    {
        cout<<"data received at hub send by the device: "<<add_s<<endl;
        cout<<"broadcasting data to all devices"<<endl;
        this->send(add_s,add_r,data);
    }
};