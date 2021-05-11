void switchEndDevices()
{
    Switch s;
    string l;
    cout<<"Enter MacAddress of Switch : ";
    cin>>l;
    int m;
    cout<<"no. of port in it: ";
    cin>>m;
    endDevices e[m+1];

    s.initialize(l,m,m);
    for(int j=1;j<=m;j++)
    {
        string mac;
        int p;
        cout<<"enter macAddress of device: ";
        cin>>mac;
        cout<<"enter empty port no to which this device will be connected(1-"<<m<<") : ";
        cin>>p;
        e[p].initialize(p,mac);
        s.Connection(p,p);
    }

    int ch=1;
    while(ch!=0)
    {
        cout<<"Enter choice 1.to sent message 2.to see device details 3.to see switch details  4.broadcast and collision domain in given network 0.to exit:  ";
        cin>>ch;
        if(ch==1)
        {
            int src,dst;
            cout<<"Enter src and dest port to send message: ";
            cin>>src>>dst;
            string message;
            cout<<"Enter Message to sent (length atleast greater than 10): ";
            cin>>message;
            tableMapping(src,dst,e,m,s,message);
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
            s.Show();
        else if(ch==4)
        {
            cout<<"Broadcast Domain: 1\n";
            cout<<"collision Domain: "<<m<<"\n"; 
        }
    }
}
