#include<bits/stdc++.h>
using namespace std;

#include "protocols/accessLayer.cpp"
#include "protocols/selectiveRepeat.cpp"
#include "protocols/stopandWait.cpp"

class Hub;
class Switch;
class endDevices;

#include "networkDevices/endDevices.cpp"
#include "networkDevices/switch.cpp"
#include "networkTopology/switchEndDevices.cpp"
#include "functionality/framing.cpp"
#include "functionality/protocolDemonstration.cpp"
#include "functionality/tableMapping.cpp"

#include "networkDevices/hub.cpp"
#include "networkTopology/switchHubD.cpp"
#include "functionality/tableMappingComplex.cpp"

int main()
{
    srand(time(0));
    cout<<"____________________________________________________________________________________________________________________________\n\n";
    cout<<"                                                             NETWORK SIMULATOR                                             \n";
    cout<<"____________________________________________________________________________________________________________________________\n\n";
    int ch=1;
    while(ch!=0)
    {
        cout<<"Select type of devices to make connection: \n";
        cout<<"1.HUB and End devices  2.Switch and End Devices   3.HUB , Switch and End Devices   0.to exit: ";
        cin>>ch;
        switch(ch)
        {
            case 1:  cout<<"RED";
                     break;
            case 2:  switchEndDevices();
                     break;
            case  3: switchHubD();
                     break;
            case 0: break;         
            default: cout<<"Invalid choice";

        }
    }
    return 0;
}