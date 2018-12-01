#include<bits/stdc++.h>
using namespace std;

int dis[2010],cnt;

struct edges{

    int u,v,w;

}edge[2010];

void bellman_ford(int n,int e)
{
    dis[0]=0;

    for(int i=0;i<n-1;i++)
    {
        cnt=0;
        for(int j=0;j<e;j++)
        {
            if(dis[edge[j].u]+edge[j].w < dis[edge[j].v])
                dis[edge[j].v]=dis[edge[j].u]+edge[j].w;

            cnt++;
        }

        if(cnt==0)
            break;
    }
}

bool negative_cycle_check(int n,int e)
{
    for(int i=0;i<e;i++)
    {
        if(dis[edge[i].u]+edge[i].w < dis[edge[i].v])
            return true;
    }

    return false;
}

void init(int n)
{
    for(int i=0;i<=n;i++)
        dis[i]=INT_MAX;
}

int main()
{
    int test,n,e;
    cin>>test;

    while(test--)
    {
        cin>>n>>e;

        init(n);

        for(int i=0;i<e;i++)
            cin>>edge[i].u>>edge[i].v>>edge[i].w;

        bellman_ford(n,e);

        bool cycle=negative_cycle_check(n,e);

        if(cycle)
            cout<<"possible";

        else
            cout<<"not possible";

        cout<<endl;
    }

    return 0;
}
