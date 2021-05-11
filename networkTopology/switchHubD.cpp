void switchHubD()
{
    Switch s;
    string l;
    cout<<"Enter MacAddress of Switch : ";
    cin>>l;
    int m;
    cout<<"no. of port in it for connecting hub: ";
    cin>>m;
    Hub h[m+1];

    s.initialize(l,m,m);
    for(int j=1;j<=m;j++)
    {
        string mac;
        int p;
        cout<<"enter macAddress of hub: ";
        cin>>mac;
        cout<<"enter empty port no to which this device will be connected(1-"<<m<<") : ";
        cin>>p;
        h[p].initialize(p,mac);
        s.Connection(p,p);
    }

    int f;
    cout<<"Total no of end devices needed to connect to hub: ";
    cin>>f;
    endDevices e[f+1];
    int d=0;
    for(int i=1;i<=m;i++)
    {
        int g;
        cout<<"Enter no of devices needed to connect to hub "<<i<<": ";
        cin>>g;
        int j=d+1;
        for(;j<=d+g;j++)
        {
            string mac;
            cout<<"Enter mac address of device: ";
            cin>>mac;
            e[j].initialize(j,mac);
            e[j].hubConnection(i);
            h[i].Connections(j);
        }
        d=j-1;
    }

    int ch=1;
    while(ch!=0)
    {
        cout<<"Enter choice 1.to sent message 2.to see device details 3.to see switch details  4.broadcast and collision domain in given network 0.to exit: ";
        cin>>ch;
        if(ch==1)
        {
            int src,dst;
            cout<<"Enter src device no. and dest device no. to send message(1-"<<f<<"): ";
            cin>>src>>dst;
            string message;
            cout<<"Enter Message to sent (length atleast greater than 10): ";
            cin>>message;
            tableMappingComplex(src,dst,e,m,s,h,message);
        }
        else if(ch==2)
        {
            int h=1;
            while(h!=0)
            {
                cout<<"Enter device no.(i.e. port no.) to see details or 0 to go back : ";
                cin>>h;
                if(h!=0)
                e[h].Show();
            }
        }
        else if(ch==3)
            s.showComplex();
        else if(ch==4)
        {
            cout<<"Broadcast Domain(Switch): 1\n";
            cout<<"Collision Domain(Switch): "<<m<<"\n\n";
            cout<<"Broadcast Domain(every Hub): 1\n"; 
            cout<<"Collision Domain(every Hub): 1\n"; 
        }
    }
}