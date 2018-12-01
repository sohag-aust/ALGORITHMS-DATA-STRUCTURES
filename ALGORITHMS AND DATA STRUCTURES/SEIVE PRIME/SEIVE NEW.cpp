#include<bits/stdc++.h>
using namespace std;

const int maxi=80;

bool visit[maxi];
map<int,int>track;

void seive()
{
    memset(visit,false,sizeof(visit));

    visit[2]=true;
    track[2]=1;

    for(int i=3;i*i<=maxi;i+=2)
    {
        if(!visit[i])
        {
            for(int j=i*i;j<=maxi;j+=i)
                visit[j]=true;
        }
    }

    int cnt=1;
    for(int i=3;i<=maxi;i++)
    {
        if(!visit[i] && i%2!=0)
            track[i]=++cnt;
        else
            track[i]=100;
    }
}

int main()
{
    seive();
    int a,b;
    cin>>a>>b;

    int diff=abs(track[a]-track[b]);

    if(diff==1) cout<<"YES";
    else cout<<"NO";
    cout<<endl;

    return 0;
}
