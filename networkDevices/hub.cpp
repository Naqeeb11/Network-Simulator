#include<bits/stdc++.h>
using namespace std;

class Hub {
    long long int ipAdress;
    long long int macAddress;
    vector<long long int> connections;  //contain end devices no. which are connected to it 
};