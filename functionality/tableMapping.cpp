void tableMapping(int src,int dst,endDevices e[],int nport,Switch &s,string message)
{
    if(s.table.find(src)==s.table.end() || s.table.find(dst)==s.table.end())
    {
        if(s.table.find(src)==s.table.end())
        {
            s.table.insert({src,e[s.connection[src]].macAddress});
            cout<<"endDevice "<<src<<" macAddress added in table\n";
        }
        for(int i=1;i<=nport;i++)
        {
            if(i==src)
            continue;
            if(i==dst && s.table.find(dst)==s.table.end())
            { 
                s.table.insert({i,e[s.connection[i]].macAddress});
                cout<<"endDevice "<<dst<<" macAddress added in table\n";
            }
        }
    }

    protocolDemonstration(message,e,src,dst); 
}