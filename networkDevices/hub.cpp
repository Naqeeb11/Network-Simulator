#include<bits/stdc++.h>
using namespace std;

class Hub {
    int hubno;
    string macAddress;
    vector<int> connections;  //contain end devices no. which are connected to it 
    public:
     
    void initialize(int hub,string macAddr)
    {
        hubno=hub;
        macAddress=macAddr;
    }

    void Connections(int deviceNo)
    {
        connections.push_back(deviceNo);
    }

    friend void tableMappingComplex(int ,int,endDevices e[] ,int ,Switch &,Hub h[],string message);
};
