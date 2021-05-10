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
    
    friend void tableMapping(int,int,endDevices e[],int,Switch,string message);
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
        macAddr=macAddress;
        nofPort=port;
        mappingDone=false;
        connection=new int[size+1];
        memset(connection,0,sizeof(connection));
    }

    friend void tableMapping(int ,int,endDevices e[] ,int ,Switch,string message);

    void Connection(int p,int dev)
    {
        connection[p]=dev;
    }
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
    srand(time(0));
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
        cout<<"Packet Lost";
        else
        {
            if(receiverWindow!=sl)
            {
                cout<<"ACK "<<receiverWindow<<"\n";
                sl++;
            }
            else
            {
                cout<<"Packet Received";
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
    vector<string> receivedMessages;
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
            cout<<"collision happened\n";
            q.push(q.front());
            q.pop();
        }
        else
        {
            if(receiverWindow[q.front()]==1 && sl==q.front())
            {
                q.pop();
                sl++,sr++;
                if(sr<5)
                q.push(sr);
                if(q.size()==1)
                {
                    sl++,sr++;
                    if(sr<5)
                    q.push(sr);
                }                
            }
            else
            {
                cout<<"Packet received\n";
                receiverWindow[q.front()]=1;
                int y=rand()%4;
                if(y==1)
                {
                    cout<<"ACK Lost\n";
                    q.push(q.front());
                    q.pop();
                }
                else
                {
                    cout<<"ACK received\n";
                    if(q.front()==sl)
                    {
                        sl++;
                        sr++;
                        if(sr<5)
                        q.push(sr);
                    }
                    q.pop();
                } 
            }
            
        }
    }
}




void tableMapping(int src,int dst,endDevices e[],int nport,Switch s,string message)
{
    if(s.mappingDone==false)
    {
        s.table.insert({src,e[s.connection[src]].macAddress});
        for(int i=1;i<=nport;i++)
        {
            if(i==src)
            continue;
            if(s.connection[i]!=0)
            s.table.insert({i,e[s.connection[i]-1].macAddress});
        }
       s.mappingDone=true;
    }
    vector<string> messages;
    //message divided into packets 
    messages=framing(message);
    //Slotted Aloha implemented
    messages=slottedAloha(messages);
}

void Construction()
{
    int n,m;
    cout<<"No. of switch needed and no. of port in it: ";
    cin>>n>>m;
    Switch s[n];
    int y;
    cout<<"Total no. of endDevices needed: ";
    cin>>y;
    endDevices e[y+1];
    int d=0;
    for(int i=0;i<n;i++)
    {
        string l;
        cout<<"Enter MacAddress of Switch "<<i+1<<": ";
        cin>>l;
        int x;
        cout<<"No. of devices you need for connection with switch "<<i+1<<" :";
        cin>>x;
        s[i].initialize(l,m,x);
        for(int j=d+1;j<=x+d;j++)
        {
            string mac;
            int p;
            cout<<"enter macAddress of device: ";
            cin>>mac;
            cout<<"enter empty port no to which this device will be connected: ";
            cin>>p;
            e[j].initialize(j,mac);
            s[i].Connection(p,j);
        }
        d=x;
    }
    int ch=1;
    while(ch==1)
    {
        int src,dst;
        cout<<"Enter src and dest port to send message: ";
        cin>>src>>dst;
        string message;
        cout<<"Enter Message to sent (length atleast greater than 10): ";
        cin>>message;
        tableMapping(src,dst,e,m,s[0],message);
        cout<<"0.to exit else to continue: ";
    }
}
