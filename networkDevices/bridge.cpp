#include<bits/stdc++.h>
using namespace std;

class Bridge {
    long long int macAddress;
    int srcAddress;
    int destAddress;
    public:
    Bridge(string t,int s,int d)
    {
        macAddress=t;
        srcAddress=s;
        destAddress=d;
    }

    bool filtering(string dataPacket,int srcport,int destport)
    {
        if(srcport==destport)
        return false;
        else
        return true;
    }
};