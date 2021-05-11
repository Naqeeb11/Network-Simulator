/*    by- SHARAD VERMA
Implemented Line coding encoder and scrambler with digital data
generator
• Digital data generator: generates completely random data sequence and
a random sequence with some fixed sub-sequences like eight consecutive
zeros.
• Line coding schemes implemented: NRZ-L, NRZ-I, Manchester, Differential Manchester, AMI.
• Scrambling schemes implemented: B8ZS, HDB3.
• Encoded data is represented by plots using graphics
*/

#include<bits/stdc++.h>
#include<time.h>
#include<graphics.h>

using namespace std;

//function to find min
int min(int a, int b)
{
	int res = a;
	if(b < a)
		res = b;
	return res;
}
//function to find longest common subsequence
//we will find a sequence of 4 or 8 zeroes
int LCS(int pattern1[], int pattern2[], int n, int m)
{
    int index=-1;
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (pattern1[i] == pattern2[j])
            {
				dp[i][j] = dp[i + 1][j + 1] + 1;
				if(dp[i][j]==m)
                   index=i;
            }
		}
	}
	return index;
}
// function to find four consecutive zeroes
void fourbitszero(int* s,int size,int* x)
{
    for(int i=0;i<10;i++)
        x[i]=-1;
    int start=0,count=0,i=0,j=0;
    while(i<size)
    {
       while(i<size&&s[i]==1)
       {
          i++;
       }
      start=i;
       while(i<size&&s[i]==0&&count<4)
       {
          count++;
           i++;
       }
      if(count==4)
       {
          count=0;
          x[j]=start;
            j++;
       }
       else
        count=0;

    }
}
// function to find 8 consecutive zeroes
void eightbitszero(int* s,int size,int* x)
{
    for(int i=0;i<3;i++)
        x[i]=-1;
    int start=0,count=0,i=0,j=0;
    while(i<size)
    {
       while(i<size&&s[i]==1)
       {
          i++;
       }
      start=i;
       while(i<size&&s[i]==0&&count<8)
       {
          count++;
           i++;
       }
      if(count==8)
       {
          count=0;
          x[j]=start;
            j++;
       }
       else
        count=0;
    }
}

// function to generate random sequence of binary data
int* generate_comp_rand(int n)
{

    int* s=new int[n];
   srand(time(0));
   for(int i=0;i<n;i++ )
   s[i]=rand()%2;
	return s;
}

int* encode()
{
	srand(time(0));
	int input;
	int encoding;
	int scrambling=-1;
	int stype=-1;
	string str;

	cout<<"Enter your choice for data generation."<<endl;
	cout<<"\n";
	cout<<"1- Random with some specific subsequences\n";
	cout<<"\n";
	cout<<"2- Complete Random \n";

    int* s;
    int size;
	cin>>input;

		switch(input)
	{
		case 1:
	      {
			cout<<"Enter your pattern\n";
			cin>>str;
        	int n1=5+rand()%7;
            int n2=5+rand()%7;
       	    int * x=generate_comp_rand(n1);
       	    int * y=generate_comp_rand(n2);
       	    size=n1+str.length()+n2;
       	    s=new int[size];
       	    for(int i=0;i<size;i++)
       	    {
       	    	if(i<n1)
       	         s[i]=x[i];
					else if(i<n1+str.length())
					s[i]=str[i-n1]-'0';
					else
					s[i]=y[i-n1-str.length()];
			}
			cout<<endl;

			break;
		}
		case 2:
            int n=20+rand()%9;
            s=generate_comp_rand(n);
            size=n;
		    break;
	}
    cout<<"FOLLOWING IS OUR INPUT:"<<endl;
			for(int i=0;i<size;i++)
			cout<<s[i];
			cout<<endl;
	cout<<"\n";
	cout<<"Enter type of encoding for the input\n";
	cout<<"\n";
	cout<<"1- NRZ-L\n";
	cout<<"\n";
	cout<<"2- NRZ-I\n";
	cout<<"\n";
	cout<<"3- Manchester\n";
	cout<<"\n";
	cout<<"4- Differential Manchester\n";
	cout<<"\n";
	cout<<"5- AMI\n";
	cout<<"\n";
	cin>>encoding;
	if(encoding==5)
	{
		cout<<"Do you want scrambling\n";
		cout<<endl;
		cout<<"1- Yes"<<endl;
		cout<<endl;
		cout<<"2- No"<<endl;
		cout<<endl;
		cin>>scrambling;
		if(scrambling==1)
        {
            cout<<"choose scrambling"<<endl;
            cout<<"1- B8ZS"<<endl;
            cout<<"2- HDB3"<<endl;
            cin>>stype;
        }
	}
	int *en;
    switch(encoding)
    {
    case 1:
        {
           //NRZL(s,size);
           break;
        }
    case 2:
        {
         en=new int[size];
         en[0]=!s[0];
         for(int i=1;i<size;i++)
         {
             if(s[i]==1)
             en[i]=!en[i-1];
             else
                en[i]=en[i-1];
         }
         cout<<"encoded data transfered is: "<<endl;
         for(int i=0;i<size;i++)
            cout<<en[i];
            cout<<endl;
        // NRZI(s,en,size,size);
        return en;
         break;
        }
    case 3:
        {
        en=new int[2*size];

        for(int i=0,j=0;i<size;i++,j=j+2)
        {
            if(s[i])
            {
                en[j]=1;
                en[j+1]=0;
            }
            else
            {
                en[j]=0;
                en[j+1]=1;
            }
        }
       // Manchester(s,size,en,2*size);
       cout<<"encoded data transfered is: "<<endl;
        for(int i=0;i<2*size;i++)
            cout<<en[i];
            cout<<endl;
            return en;
        break;
        }
    case 4:
        {
         en=new int[2*size];
         if(s[0])
         {
             en[0]=1;
             en[1]=0;
         }
         else
         {
             en[0]=0;
             en[1]=1;
         }
         for(int i=1,j=2;i<size;i++,j++)
         {
           if(s[i])
           {
               en[j]=en[j-1];
               j++;
               en[j]=!en[j-1];
           }
           else
           {
               en[j]=!en[j-1];
               j++;
               en[j]=!en[j-1];
           }
         }
         cout<<"encoded data transfered is: "<<endl;
         for(int i=0;i<2*size;i++)
            cout<<en[i];
        //DManchester(s,size,en,2*size);
        cout<<endl;
        return en;
        }
    case 5:
        {
            if(scrambling==2)
            {
            int flag=1;
            en=new int[size];
            for(int i=0;i<size;i++)
            {
                if(s[i])
                {
                    en[i]=flag;
                    flag=!flag;
                }
                else
                {
                    en[i]=-1;
                }
            }
            cout<<"encoded data transfered is: "<<endl;
             for(int i=0;i<size;i++)
            cout<<en[i];
            cout<<endl;
           // AMI(s,size,en,size);
           return en;
            }
            else if(scrambling==1)
            {
                if(stype==1)
                {

                    int *x;
                    x=new int[3];

                    eightbitszero(s,size,x);
                    int flag=1;
                    en=new int[size];
                    for(int i=0;i<size;i++)
                      {
                        if(s[i])
                        {
                         en[i]=flag;
                         flag=!flag;
                       }
                      else
                      {
                       en[i]=-1;
                       }
                      }
                    for(int i=0;i<3;i++)
                    {
                      if(x[i]==-1)
                       break;
                      else
                      {
                          int v=x[i];
                          while(v>=0&&en[v]==-1)
                            v--;
                            int flag1;
                            if(v==-1)
                                flag1=1;
                            else
                          flag1=en[v];
                          v=x[i];
                          v+=3;
                          en[v]=flag1;
                          v++;
                          en[v]=!flag1;
                          flag1=!flag1;
                          v++;
                          v++;
                          en[v]=flag1;
                          v++;
                          en[v]=!flag1;
                          flag1=!flag1;
                      }
                    }
                     cout<<endl<<"SCRAMBLED DATA IS:"<<endl;
                     for(int i=0;i<size;i++)
                     {
                         if(en[i]==-1)
                            cout<<0;
                         else
                            cout<<1;
                     }
                     cout<<endl;
                       // B8ZS(s,size,en,size);
                       cout<<"encoded data transfered is: "<<endl;
                        for(int i=0;i<size;i++)
            cout<<en[i];
            cout<<endl;
            return en;
                }
                else if(stype==2)
                {
                    int *x;
                    x=new int[10];
                    fourbitszero(s,size,x);

                    int flag=1;
                    en=new int[size];
                    for(int i=0;i<size;i++)
                      {
                        if(s[i])
                        {
                         en[i]=flag;
                         flag=!flag;
                       }
                      else
                      {
                       en[i]=-1;
                       }
                      }
                      cout<<endl;

                      for(int i=0;i<10;i++)
                    {
                      if(x[i]==-1)
                       break;
                      else
                      {
                          int v=-1,u=x[i];
                          int parity=0;
                          u--;
                          while(u>=0)
                            {
                               if(v==-1&&en[u]!=-1)
                               {
                                v=u;
                                parity++;
                               }
                               else if(en[u]!=-1)
                                parity++;
                               u--;
                            }
                            parity=parity%2;
                            int flag1;
                            if(v==-1)
                                flag1=1;
                            else
                            flag1=en[v];
                          v=x[i];

                          if(parity)
                          {
                              v+=3;
                              en[v]=flag1;
                          }
                          else
                          {
                              if(v==0)
                              {
                                  en[v]=1;
                                v+=3;
                                en[v]=1;
                              }
                              else
                              {
                              en[v]=!flag1;
                              flag1=!flag1;
                              v+=3;
                              en[v]=flag1;
                              flag1=!flag1;
                              }
                            for(int p=v+1;p<size;p++)
                            {
                                if(en[p]!=-1)
                                {
                                    en[p]=!en[p];
                                }
                            }
                          }
                      }
                    }
                     cout<<endl<<"SCRAMBLED DATA IS:"<<endl;
                     for(int i=0;i<size;i++)
                     {
                         if(en[i]==-1)
                            cout<<0;
                         else
                            cout<<1;
                     }
                     cout<<endl;
                  // HDB3(s,size,en,size);
                  cout<<"encoded data transfered is: "<<endl;
                   for(int i=0;i<size;i++)
            cout<<en[i];
            cout<<endl;
            return en;
                }
            }
            break;
        }
    }
	cout<<"\n";

}
