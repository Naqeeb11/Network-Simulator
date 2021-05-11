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
    protocolDemonstration(message,e,src,dst); 
}