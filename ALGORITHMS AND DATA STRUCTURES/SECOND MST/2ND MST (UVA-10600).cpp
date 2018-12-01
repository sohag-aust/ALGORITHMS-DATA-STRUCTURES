#include<bits/stdc++.h>
using namespace std;

#define maxi 110
#define inf 1e9

struct edges
{
    int u,v,w;
}ed;

bool cmp(edges a,edges b)
{
    return a.w < b.w;
}

int node,edge,ind;
vector<edges>vec;
int parent[maxi];
int selected_edge[maxi];

void init()
{
    for(int i=1;i<=node;i++)
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

int MST_1()
{
    int sum;

    sum = ind = 0;

    for(int i=0;i<vec.size();i++)
    {
        int x = find_union(vec[i].u);
        int y = find_union(vec[i].v);

        if(x != y)
        {
            _set_union(x,y);
            sum += vec[i].w;
            selected_edge[ind++] = i;
        }
    }

    return sum;
}

int MST_2()
{
    int mini = inf,sum,cnt;

    for(int i=0;i<ind;i++)
    {
        init();

        cnt = sum = 0;

        for(int j=0;j<vec.size();j++)
        {
            if(selected_edge[i] != j)
            {
                int x = find_union(vec[j].u);
                int y = find_union(vec[j].v);

                if(x != y)
                {
                    _set_union(x,y);
                    sum += vec[j].w;
                    cnt++;
                }
            }
        }

        if(cnt == node-1 && mini > sum)
            mini = min(mini,sum);
    }

    return mini;
}

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        cin>>node>>edge;

        init();
        vec.clear();
        memset(selected_edge,0,sizeof(selected_edge));

        while(edge--)
        {
            cin>>ed.u>>ed.v>>ed.w;
            vec.push_back(ed);
        }

        sort(vec.begin(),vec.end(),cmp);

        int mst1 = MST_1();
        int mst2 = MST_2();

        cout<<mst1<<" "<<mst2<<endl;
    }

    return 0;
}
