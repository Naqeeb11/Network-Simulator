class endDevices {
    int deviceNo;
    int hubno;  //if connected to hub;
    string macAddress;
    map<string,int> messagesReceived;  //store messages and sender info (device no) 
    map<string,int> messagesSent;  //store messages and dest info (device no) 
    public:
    void initialize(int d,string macAddr)
    {
        deviceNo=d;
        macAddress=macAddr;
    }
    void messageStorageReceived(string message,int src)
    {
        messagesReceived.insert({message, src});
    }

    void messageStorageSent(string message, int dest)
    {
        messagesSent.insert({message, dest});
    }
    
    void hubConnection(int hub)
    {
        hubno=hub;
    }

    int giveHub()
    {
        return hubno;
    }

    void Show()
    {
        cout<<"\n";
        cout<<"device No: "<<deviceNo<<"\n";
        cout<<"Mac Address: "<<macAddress<<"\n";
        cout<<"Messages Received: \n";
        cout<<"Messages         Sender Info(device no)\n\n";
        for(auto i: messagesReceived)
        cout<<i.first<<"        "<<i.second<<"\n"; 
        cout<<"Messages Sent: \n";
        cout<<"Messages         Destination Info(device no)\n\n";
        for(auto i: messagesSent)
        cout<<i.first<<"        "<<i.second<<"\n"; 
    }

    friend void tableMapping(int,int,endDevices e[],int,Switch &,string message);
    friend void tableMappingComplex(int ,int,endDevices e[] ,int ,Switch &,Hub h[],string message);
};


