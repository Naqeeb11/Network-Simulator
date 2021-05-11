void protocolDemonstration(string message,endDevices e[],int src ,int dst)
{
    vector<string> messages;
    
    messages=framing(message);  //message divided into packets 

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
