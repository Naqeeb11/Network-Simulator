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