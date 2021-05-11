#include<bits/stdc++.h>
using namespace std;

class Switch;

class endDevices {
    int deviceNo;
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
    
    void Show()
    {
        cout<<"device No: "<<deviceNo<<"\n";
        cout<<"Mac Address: "<<macAddress<<"\n";
        cout<<"Messages Received: \n\n";
        cout<<"Messages         Sender Info(device no)\n";
        for(auto i: messagesReceived)
        cout<<i.first<<"        "<<i.second<<"\n"; 
        cout<<"Messages Sent: \n\n";
        cout<<"Messages         Destination Info(device no)\n";
        for(auto i: messagesSent)
        cout<<i.first<<"        "<<i.second<<"\n"; 
    }

    friend void tableMapping(int,int,endDevices e[],int,Switch &,string message);
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
    friend void tableMapping(int ,int,endDevices e[] ,int ,Switch &,string message);
};

vector<string> framing(string message)
{
    vector<string> messages;
    int l=message.length()/5;
    int i=0;
    for(;i<4;i++)
        messages.push_back(message.substr(i*l,l));
    messages.push_back(message.substr(i*l));
    return messages;
} 

//implementation of Slotted Aloha
vector<string> slottedAloha(vector<string> messages)
{
    vector<string> ans;
    int i=10;
    int l=0;
    unordered_set<int> s; //slot used
    queue<int> q; //sequence of packet
    for(int i=0;i<5;i++)
    q.push(i);
    while(i-- && !q.empty())
    {
        int n=rand()%6;
        if(s.find(n)==s.end())
        {
            ans.push_back(messages[q.front()]);
            s.insert(n);
            cout<<"Ack received packet "<<q.front()<<" delivered\n";
            q.pop();
        }
        else
        {
            cout<<"Slot missed for packet "<<q.front()<<"\n";
            q.push(q.front());
            q.pop();
        }
    }

    if(q.empty())
    {
        cout<<"message transfered successfully\n";
        return messages;
    }
    else
    {
        cout<<"Maximum retry limit exhausted which results in some packet lost\n";
        return ans;
    }
}

//implementation of stop and wait protocol
void stopWait(vector<string> messages)
{
    int receiverWindow=0,sl=0;
    while(sl<5)
    {
        int n=rand()%6;
        if(n==2 || n==4)
        cout<<"Packet "<<sl<<" Lost\n";
        else
        {
            if(receiverWindow!=sl)
            {
                cout<<"ACK "<<receiverWindow<<"\n";
                sl++;
            }
            else
            {
                cout<<"Packet "<<sl<<" Received\n";
                receiverWindow++;
                int m=rand()%3;
                if(m==2)
                cout<<"ACK Lost\n";
                else
                {
                    cout<<"ACK "<<receiverWindow<<"\n";
                    sl++;
                }
            }   
        }
    }
}

//implementation of selective repeat
void selectiveRepeat(vector<string> messages)
{
    //window size of two taken
    int sl=0,sr=1; //sender window
    int receiverWindow[5]; //receiver window
    memset(receiverWindow,0,sizeof(receiverWindow));
    queue<int> q;
    q.push(0);
    q.push(1);
    while(sl<5)
    {
        int n=rand()%5;
        if(n==q.front())
        {
            cout<<"collision happened packet "<<q.front()<<" lost\n";
            q.push(q.front());
            q.pop();
        }
        else
        {
            if(receiverWindow[q.front()]==1 && sl==q.front())
            {
                q.pop();
                cout<<"ACK "<<sl<<" received\n";
                sl++,sr++;
                if(sr<5)
                q.push(sr);
                if(q.size()==1 || q.size()==0)
                {
                    sl++,sr++;
                    if(sr<5)
                    q.push(sr);
                }                
            }
            else
            {
                cout<<"Packet "<<q.front()<<" received\n";
                receiverWindow[q.front()]=1;
                int y=rand()%4;
                if(y==1)
                {
                    cout<<"ACK "<<q.front()<<" Lost\n";
                    q.push(q.front());
                    q.pop();
                }
                else
                {
                    cout<<"ACK "<<q.front()<<" received\n";
                    if(q.front()==sl)
                    {
                        sl++;
                        sr++;
                        if(sr<5)
                        q.push(sr);
                        if(q.size()==2 && sl!=4)
                        {
                            sl++,sr++;
                            if(sr<5)
                            q.push(sr);
                        }  
                    }
                    q.pop();
                } 
            }
            
        }
    }
}




void tableMapping(int src,int dst,endDevices e[],int nport,Switch &s,string message)
{
    if(s.mappingDone==false)
    {
        s.table.insert({src,e[s.connection[src]].macAddress});
        for(int i=1;i<=nport;i++)
        {
            if(i==src)
            continue;
            if(s.connection[i]!=0)
            s.table.insert({i,e[s.connection[i]].macAddress});
        }
       s.mappingDone=true;
    }
    vector<string> messages;
    //message divided into packets 
    messages=framing(message);
    //Slotted Aloha implemented
    int ch;
    cout<<"Enter choice for Demonstration of protocol 1.Slotted Aloha   2.Stop and Wait   3.Selective Repeat: ";
    cin>>ch;
    cout<<"\n";
    if(ch==1)
    {
        messages=slottedAloha(messages);
        string mem="";
        for(int i=0;i<messages.size();i++)
        mem+=messages[i];
        if(mem.size()!=message.size())
        {
            e[src].messageStorageSent(message,dst);
            e[dst].messageStorageReceived(mem,src);
        }   
        else
        {
            e[src].messageStorageSent(message,dst);
            e[dst].messageStorageReceived(message,src);
        }
    }
    else if(ch==2)
    {
        stopWait(messages);
        e[src].messageStorageSent(message,dst);
        e[dst].messageStorageReceived(message,src);
    }
    else if(ch==3)
    {
        selectiveRepeat(messages);
        e[src].messageStorageSent(message,dst);
        e[dst].messageStorageReceived(message,src);
    }
    
}

void Construction()
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
            case 2:  Construction();
                     break;
            case  3: cout<<"DARK";
                     break;
            case 0: break;         
            default: cout<<"Invalid choice";

        }
    }
    return 0;
}