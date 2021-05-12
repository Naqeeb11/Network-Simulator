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
        delay(1000);
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