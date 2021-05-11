class Switch {
    string  macAddress;
    int nofPort;
    map<int,string> table;
    map<int,pair<string,vector<string>>> tableComplex;  //Used when network contain Switch, hub and end devices
    bool mappingDone;
    int *connection;
    public:
    void initialize(string macAddr,int port,int size)
    {
        macAddress=macAddr;
        nofPort=port;
        mappingDone=false;
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
        if(mappingDone==true)
        {
            cout<<"Port       Mac Address: \n";
            for(int i=1;i<=nofPort;i++)
            cout<<i<<"             "<<table[i]<<"\n";
        }
        else
        cout<<"Mapping not done\n";
    }

    void showComplex()
    {
        cout<<"\n";
        cout<<"Mac Address: "<<macAddress<<"\n";
        cout<<"No of port: "<<nofPort<<"\n";
        if(mappingDone==true)
        {
            cout<<"Port(switch)       Mac Address(HUB)                               Mac Address (Devices): \n";
            for(int i=1;i<=nofPort;i++)
            {
                cout<<"       "<<i<<"                "<<tableComplex[i].first<<"                               ";
                for(int j=0;j<tableComplex[i].second.size();j++)
                cout<<"      "<<tableComplex[i].second[j];
                cout<<"\n";
            }
        }
        else
        cout<<"Mapping not done\n";
    }

    friend void tableMapping(int ,int,endDevices e[] ,int ,Switch &,string message);
    friend void tableMappingComplex(int ,int,endDevices e[] ,int ,Switch &,Hub h[],string message);
};