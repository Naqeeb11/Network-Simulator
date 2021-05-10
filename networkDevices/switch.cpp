#include<bits/stdc++.h>
using namespace std;

class endDevices {
    int deviceNo;
    string macAddress;
    public:
    void initialize(int d,string macAddr)
    {
        deviceNo=d;
        macAddress=macAddr;
    }
    
    friend void tableMapping(int,int,endDevices,int,Switch);
};

class Switch {
    string  macAddress;
    int nofPort;
    map<int,string> table;
    bool mappingDone;
    int *connection;
    public:
    void initialize(string macAddr,int port,int size)
    {
        macAddr=macAddress;
        nofPort=port;
        mappingDone=false;
        connection=new int[size+1];
    }

    friend void tableMapping(int ,int,endDevices,int ,Switch);
    // {
    //     if(mappingDone==false)
    //     {
    //         table.insert({src,e.macAddress});
    //         for(int i=1;i<=nport;i++)
    //         {
    //             if(i==src)
    //             continue;

    //         }
    //     }
    // }

    void Connection(int p,int dev)
    {
        connection[p]=dev;
    }
};

void tableMapping(int src,int dst,endDevices e,int nport,Switch s)
{
        if(s.mappingDone==false)
        {
            s.table.insert({src,e.macAddress});
            for(int i=1;i<=nport;i++)
            {
                if(i==src)
                continue;

            }
        }
}

void Construction()
{
    int n,m;
    cout<<"No. of switch needed and no. of port in it: ";
    cin>>n>>m;
    Switch s[n];
    int y;
    cout<<"Total no. of endDevices needed: ";
    cin>>y;
    endDevices e[y];
    int d=0;
    for(int i=0;i<n;i++)
    {
        string l;
        cout<<"Enter MacAddress of Switch "<<i+1<<": ";
        cin>>l;
        int x;
        cout<<"No. of devices you need for connection with switch "<<i+1<<" :";
        cin>>x;
        s[i].initialize(l,m,x);
        for(int j=d+1;j<=x+d;j++)
        {
            string mac;
            int p;
            cout<<"enter macAddress of device: ";
            cin>>mac;
            cout<<"enter empty port no to which this device will be connected: ";
            cin>>p;
            e[j].initialize(j,mac);
            s[i].Connection(p,j);
        }
        d=x;
    }
    int ch=1;
    while(ch==1)
    {
        int src,dst;
        cout<<"Enter src and dest port to send message: ";
        cin>>src>>dst;
        tableMapping(src,dst,e[0],m,s[0]);
        cout<<"0.to exit else to continue: ";
    }
}
