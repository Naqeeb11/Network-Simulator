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