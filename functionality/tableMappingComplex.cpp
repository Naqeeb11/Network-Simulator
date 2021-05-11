void tableMappingComplex(int src,int dst,endDevices e[],int nport,Switch &s,Hub h[],string message)
{
    if(s.mappingDone==false)
    {
        vector<string> add;
        int hubno=e[src].giveHub();
        for(int i=0;i<h[hubno].connections.size();i++)
        {
            add.push_back(e[h[hubno].connections[i]].macAddress);
        }
        s.tableComplex.insert({e[src].giveHub(),{h[e[src].giveHub()].macAddress,add}});

        for(int i=1;i<=nport;i++)
        {
            if(hubno==i)
            continue;
            vector<string> add1;
            for(int j=0;j<h[i].connections.size();j++)
            add1.push_back(e[h[i].connections[j]].macAddress);
            s.tableComplex.insert({i,{h[i].macAddress,add1}});
        }

       s.mappingDone=true;
    }   
    protocolDemonstration(message,e,src,dst); 

    cout<<"\n";
    if(e[src].giveHub()==e[dst].giveHub())
    cout<<"Here packet is dropped by switch as source and destination lies within same local network\n";
    else
    cout<<"Here packet is forwarded by switch as source and destination lies in different network\n";
    cout<<"\n";
}

