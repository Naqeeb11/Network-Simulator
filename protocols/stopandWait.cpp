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