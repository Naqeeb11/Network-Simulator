bool search(vector<string> arr, string mac)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==mac)
        return true;
    }
    return false;
}

void tableMappingComplex(int src,int dst,endDevices e[],int nport,Switch &s,Hub h[],string message)
{
    int hubno=e[src].giveHub();
    int hubno1=e[dst].giveHub();
    if((s.tableComplex.find(hubno)==s.tableComplex.end() || search(s.tableComplex[hubno].second,e[src].macAddress)==false) 
    || (s.tableComplex.find(hubno1)==s.tableComplex.end() || search(s.tableComplex[hubno1].second,e[dst].macAddress)==false ))
    {
        vector<string> add;
        if(s.tableComplex.find(hubno)==s.tableComplex.end())
        s.tableComplex.insert({hubno,{h[hubno].macAddress,add}});

        for(int i=0;i<h[hubno].connections.size();i++)
        {
            if(h[hubno].connections[i]==src && search(s.tableComplex[hubno].second,e[src].macAddress)==false)
            {
                s.tableComplex[hubno].second.push_back(e[src].macAddress);
                cout<<"endDevice "<<src<<" macAddress added in table\n";
            }

        }

        for(int i=1;i<=nport;i++)
        {
            if(i==hubno1)
            {
                if( s.tableComplex.find(hubno1)==s.tableComplex.end())
                s.tableComplex.insert({hubno1,{h[hubno1].macAddress,add}});
            } 

            for(int j=0;j<h[i].connections.size();j++)
            {
               if(h[i].connections[j]==dst && s.tableComplex.find(i)!=s.tableComplex.end() && search(s.tableComplex[i].second,e[dst].macAddress)==false)
               {
                   s.tableComplex[i].second.push_back(e[dst].macAddress);
                   cout<<"endDevice "<<dst<<" macAddress added in table\n";
               }
            }
        }
    }   

    protocolDemonstration(message,e,src,dst); 

    cout<<"\n";
    if(e[src].giveHub()==e[dst].giveHub())
    {
        cout<<"Here packet is dropped by switch as source and destination lies within same local network\n";
        for(int i=0;i<h[e[src].giveHub()].connections.size();i++)
        {
            if(h[e[src].giveHub()].connections[i]==src)
            continue;
            if(h[e[src].giveHub()].connections[i]==dst)
            cout<<"Packet accepted by end Device "<<h[e[dst].giveHub()].connections[i]<<"\n";
            else
            cout<<"Packet dropped by end Device "<<h[e[src].giveHub()].connections[i]<<"\n";
            delay(500);
        }
    }
    else
    {
        cout<<"Here packet is forwarded by switch as source and destination lies in different network\n\n";
        for(int i=0;i<h[e[src].giveHub()].connections.size();i++)
        {
            if(h[e[src].giveHub()].connections[i]==src)
            continue;
            cout<<"Packet dropped by end Device "<<h[e[src].giveHub()].connections[i]<<"\n";
            delay(500);
        }

        for(int i=0;i<h[e[dst].giveHub()].connections.size();i++)
        {
            if(h[e[dst].giveHub()].connections[i]==dst)
            cout<<"Packet accepted by end Device "<<h[e[dst].giveHub()].connections[i]<<"\n";
            else
            cout<<"Packet dropped by end Device "<<h[e[dst].giveHub()].connections[i]<<"\n";
            delay(500);
        }
    }
    cout<<"\n";
}

