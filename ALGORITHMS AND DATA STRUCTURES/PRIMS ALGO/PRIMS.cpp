#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
vector<PII>v[1000];
int MAX=1234567;

struct Node
{
    int u,cost;
    Node(int _u,int _cost)
    {
        u=_u;
        cost=_cost;
    }
};
bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}

priority_queue<Node>PQ;
int cost[1000],taken[1000];

int prim(int s)
{
    for(int i=0; i<100; i++)
    {
        cost[i]=MAX;
        taken[i]=0;
    }
    cost[s]=0;
    PQ.push(Node(s,0));
    int ans=0;
    while(!PQ.empty())
    {
        Node x=PQ.top();
        PQ.pop();
        if(taken[x.u])
        {
            continue;
        }
        taken[x.u]=1;
        ans+=x.cost;
        for(int i=0; i<v[x.u].size(); i++)
        {
            int p=v[x.u][i].first;
            int p1=v[x.u][i].second;
            if(taken[p]) continue;
            if(p1<cost[p])
            {
                PQ.push(Node(p,p1));
                cost[p]=p1;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    int sum=prim(1);

    cout<<sum<<endl;

    return 0;
}
