class Switch {
    string  macAddress;
    int nofPort;
    map<int,string> table;
    map<int,pair<string,vector<string>>> tableComplex;  //Used when network contain Switch, hub and end devices
    int *connection;
    public:
    void initialize(string macAddr,int port,int size)
    {
        macAddress=macAddr;
        nofPort=port;
        connection=new int[size+1];
        for(int i=0;i<size+1;i++)
        connection[i]=0;
    }

    void Connection(int p,int dev)
    {
        if(connection[p]==0)
        connection[p]=dev;
        else
        cout<<"already occupied\n";
    }

    void Show()
    {
        cout<<"\n";
        cout<<"Mac Address: "<<macAddress<<"\n";
        cout<<"No of port: "<<nofPort<<"\n";
        cout<<"Port       Mac Address: \n\n";
        if(table.size()!=0)
        {
            for(auto i:table)
            cout<<i.first<<"             "<<i.second<<"\n\n";
        }
    }

    void showComplex()
    {
        cout<<"\n";
        cout<<"Mac Address: "<<macAddress<<"\n";
        cout<<"No of port: "<<nofPort<<"\n";
        cout<<"Port(switch)       Mac Address(HUB)                               Mac Address (Devices): \n\n";
        if(tableComplex.size()!=0)
        {
            for(auto i: tableComplex)
            {
                cout<<"       "<<i.first<<"                "<<i.second.first<<"                               ";
                for(int j=0;j<i.second.second.size();j++)
                cout<<"      "<<i.second.second[j];
                cout<<"\n";
            }
            cout<<"\n";  
        }          
    }

    friend void tableMapping(int ,int,endDevices e[] ,int ,Switch &,string message);
    friend void tableMappingComplex(int ,int,endDevices e[] ,int ,Switch &,Hub h[],string message);
};
