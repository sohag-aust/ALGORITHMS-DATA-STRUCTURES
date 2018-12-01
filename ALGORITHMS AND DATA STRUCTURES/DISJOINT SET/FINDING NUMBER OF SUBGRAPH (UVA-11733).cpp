#include<bits/stdc++.h>
using namespace std;

#define maxi 10010

struct edges
{
    int u,v,w;
} ed;

vector<edges>vec,ans;
int parent[maxi];

bool cmp(edges a,edges b)
{
    return a.w < b.w;
}

void init()
{
    for(int i=1; i<maxi; i++)
        parent[i] = i;
}

int find_union(int val)
{
    while(val != parent[val])
        val = parent[val];

    return val;
}

void _set_union(int x,int y)
{
    if(x > y)
        parent[x] = y;
    else
        parent[y] = x;
}

int main()
{
    int test,cs=0;

    cin>>test;

    while(test--)
    {
        int sum,cnt;
        sum = cnt = 0;

        init();
        vec.clear();
        ans.clear();

        int node,edge,airport;
        cin>>node>>edge>>airport;

        while(edge--)
        {
            cin>>ed.u>>ed.v>>ed.w;
            vec.push_back(ed);
        }

        sort(vec.begin(),vec.end(),cmp);

        for(int i=0; i<vec.size(); i++)
        {
            int x = find_union(vec[i].u);
            int y = find_union(vec[i].v);

            if(x != y)
            {
                if(vec[i].w < airport)
                {
                    _set_union(x,y);
                    sum += vec[i].w;
                }
            }
        }

        for(int i=1; i<=node; i++) /// counting number of subgraph
        {
            if(parent[i] == i)
                cnt++;
        }

        cout<<"Case #"<<++cs<<": "<<((airport * cnt) + sum)<<" "<<cnt<<endl;
    }

    return 0;
}

