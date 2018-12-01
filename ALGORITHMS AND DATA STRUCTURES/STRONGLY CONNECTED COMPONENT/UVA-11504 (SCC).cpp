/// NUMBER OF CONNECTED COMPONENT.. THAT MEANS NUMBER OF NODE THAT CAN TRAVERSE FROM ONE NODE....
/// ONLY DFS DIE ETAR TRACK RAKHA JAINA CZ SEKHANE NUMBER OF CONNECTED COMPONENT (NOT STRONGLY CONNECTED COMPONENT) TRACK RAKHA JAINA...

#include<bits/stdc++.h>
using namespace std;

#define maxi 100010

int node,edge;

stack<int>st;
int visit[maxi];
vector<int>edges[maxi];
vector<int>connected;

int total_connected_component;

void init()
{
    for(int i=0;i<maxi;i++)
        edges[i].clear();

    connected.clear();
}

void dfs(int i)
{
    visit[i] = 1;
    int sz = edges[i].size();

    for(int j=0;j<sz;j++)
    {
        int val = edges[i][j];

        if(!visit[val])
            dfs(val);
    }

    connected.push_back(i);
}

void connected_component(int i)
{
    visit[i] = 1;

    int sz = edges[i].size();

    for(int j=0;j<sz;j++)
    {
        int val = edges[i][j];

        if(!visit[val])
            connected_component(val);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin>>test;

    while(test--)
    {
        init();

        cin>>node>>edge;

        while(edge--)
        {
            int u,v;
            cin>>u>>v;

            edges[u].push_back(v);
        }

        memset(visit,0,sizeof(visit));

        for(int i=1;i<=node;i++)
        {
            if(!visit[i])
                dfs(i);
        }

        memset(visit,0,sizeof(visit));

        reverse(connected.begin(),connected.end());

        total_connected_component = 0;

        for(int i=0;i<connected.size();i++)
        {
            int val = connected[i];

            if(!visit[val])
            {
                total_connected_component++;
                connected_component(val);
            }
        }

        cout<<total_connected_component<<endl;
    }

    return 0;
}

