#include<bits/stdc++.h>
using namespace std;

vector<int>pfact;
map<int,bool>mp;
int visit[1000];
int n;

void sieve()
{
    memset(visit,1,sizeof(visit));

    for(int i=0;i<pfact.size();i++)
    {
        int val = pfact[i];

        if(visit[val])
        {
            visit[val] = 0;

            for(int j=val+val;j<=n;j+=val)
            {
                visit[j] = 0;
            }
        }
    }
}

void prime_fact(int n)
{
    while(n%2==0)
    {
        if(!mp[2])
        {
            pfact.push_back(2);
            mp[2] = true;
        }

        n/=2;
    }

    for(int i=3; i*i<=n; i+=2)
    {
        while(n%i==0)
        {
            if(!mp[i])
            {
                pfact.push_back(i);
                mp[i] = true;
            }

            n/=i;
        }
    }

    if(n>2) pfact.push_back(n);
}

int main()
{
    cout<<"Enter a number: ";
    cin>>n;

    prime_fact(n);
    sieve();

    cout<<"\nRelative Primes of "<<n<<" are -> ";

    for(int i=1;i<=n;i++)
    {
        if(visit[i])
            cout<<i<<" ";
    }

    cout<<endl;

    return 0;
}
