#include<bits/stdc++.h>
using namespace std;

int parent[100],res=0;
bool visit[100];
int dis[100];
map<int,int>mp;
vector<int>v,ans;
int n, m;
int source,reach;
bool have_negative_cycle = false;

struct edges
{
    int u;
    int v;
    int w;
} edge [100];

void make_parent(int n)
{
    for(int i=0; i<=n; i++)
        parent[i]=i;
}

void init(int n)
{
    for(int i=0;i<=n;i++)
        dis[i]=INT_MAX;
}

void print(int last)
{
    ///if(parent[last]==last)
       /// res=1;

    if(mp[parent[last]]==1)
        return ;

    v.push_back(parent[last]);

    mp[parent[last]]++;

    if(parent[last]!=last)
        print(parent[last]);

    if(!visit[parent[last]])
    {
        ans.push_back(parent[last]);
        visit[parent[last]]=true;
    }
}

void bellman_ford(int s)
{
    dis[s]=0;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(dis[edge[j].u] + edge[j].w < dis[edge[j].v] )
            {
                parent[edge[j].v] = edge[j].u;
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
            }
        }
    }

    print(reach);
}

void negative_cycle_check()
{
    for(int j=0; j<m; j++)
    {
        if(dis[edge[j].u] + edge [j].w < dis[edge[j].v])
        {
            have_negative_cycle = true;
            return ;
        }
    }
}

int main ()
{
    cout<<"Enter the number of node: ";
    cin>>n;

    cout<<"Enter the number of edges: ";
    cin>>m;

    make_parent(n);
    init(n);

    cout<<"\nEnter the relation between edges and their weight ->> "<<endl;

    for ( int i = 0; i < m; i++ )
        cin>>edge[i].u>>edge[i].v>>edge[i].w;


    cout<<"\nEnter source node: ";
    cin>>source;
    cout<<"Enter reach node: ";
    cin>>reach;

    bellman_ford(source);


    if(!visit[reach])
        ans.push_back(reach);


    negative_cycle_check();

    if(have_negative_cycle || dis[reach] == INT_MAX)
    {
        cout<<"\nNegative Cycle Possible. :( ...."<<endl;
        cout<<"\nThe Negative Cycle is ->> "<<endl;

        for(int i=v.size()-1; i>=0; i--)
            cout<<v[i]<<" ";
        cout<<endl;
    }

    else
    {
        cout<<"\nThere is no Negative Cycle. :) ...."<<endl;
        cout<<"\nThe Shortest path is ->> "<<endl;

        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;

        cout<<"\nMinimum cost is ->: "<<dis[reach]<<endl;
    }

    return 0;
}

/**
this has negative cycle->>

4 4
0 1 1
1 2 -5
2 3 2
3 1 2

source: 0
reach: 3


this has no negative cycle->>

4 4
0 1 10
1 2 20
2 3 30
3 0 -60

source: 0
reach: 3
*/


