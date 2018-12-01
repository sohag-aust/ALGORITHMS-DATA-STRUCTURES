#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll parent[1010];

struct edges
{
    int x,y,w;
}curr;

vector<edges>v;
vector<ll>ans;

void make_set(ll n)
{
    for(ll i=0; i<=n; i++)
        parent[i] = i;
}

bool cmp(edges a, edges b)
{
    return (a.w < b.w);
}

ll find_set(ll u)
{
    if(u == parent[u]) return u;

    return find_set(parent[u]);
}

void make_union(ll uu , ll vv)
{
    if(uu > vv) parent[vv] = uu;
    else parent[uu] = vv;
}

void MST(ll edge)
{
    for(int i=0; i<edge; i++)
    {
        int uu = find_set (v[i].x);
        int vv = find_set (v[i].y);

        if(uu != vv)
        {
            make_union(uu,vv);
        }

        else
        {
            ans.push_back(v[i].w);
        }
    }
}

int main()
{
    ll node,edge;

    while(cin>>node>>edge)
    {
        if(!node) break;

        v.clear();
        ans.clear();

        make_set(node);

        for(int i=0; i<edge; i++)
        {
            cin>>curr.x>>curr.y>>curr.w;
            v.push_back(curr);
        }

        sort(v.begin(),v.end(),cmp);

        MST(edge);

        int sz = ans.size();

        if(sz == 0) cout<<"forest";

        else
        {
            for(int i=0;i<sz;i++)
            {
                if(i<sz-1) cout<<ans[i]<<" ";
                else cout<<ans[i];
            }
        }

        cout<<endl;
    }

    return 0;
}

