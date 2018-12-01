/// UVA-10462
#include<bits/stdc++.h>
using namespace std;

#define maxi 500
#define inf 1e9

int node,edge;
int ans,ind,cnt;
int mini;

struct edges
{
    int u,v,w;
} ed;

bool cmp(edges a,edges b)
{
    return a.w < b.w;
}

vector<edges>vec;
int parent[maxi];
int edgeTaken[maxi];

void init()
{
    for(int i=1; i<maxi; i++)
        parent[i] = i;
}

int find_union(int val)
{
    if(val == parent[val])
        return val;

    return(parent[val] = find_union(parent[val]));
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
    ans = -1;
    int sum;

    sum = cnt = ind = 0;

    for(int i=0; i<vec.size(); i++)
    {
        int x = find_union(vec[i].u);
        int y = find_union(vec[i].v);

        if(x != y)
        {
            _set_union(x,y);

            edgeTaken[ind++] = i;
            sum += vec[i].w;
            cnt++;
        }
    }

    if(cnt == node-1)
        ans = sum;

    return ans;
}

int MST_2()
{
    mini = inf;

    for(int i=0; i<ind; i++)
    {
        init();
        ans = cnt = 0;

        for(int j=0; j<vec.size(); j++)
        {
            if(edgeTaken[i] != j) /// edgetaken er moddhe 1st MST er sob edge ace.. tai 2nd MST ber krte hole 1st MST er edge gula bad die onno gula sob chk kore dekhbo kongula nile 2nd MST ber kora jai..
            {
                int x = find_union(vec[j].u);
                int y = find_union(vec[j].v);

                if(x != y)
                {
                    _set_union(x,y);
                    cnt++;
                    ans += vec[j].w;
                }
            }
        }

        if(cnt == node-1 && mini>ans) /// cnt means edge joto gula nilam.. we know MST te edge songkha node-1 thake.. jodi ei cndition fill up hoi then amra ans save kore rakhbo.
            mini = ans;
    }

    return mini;
}

int main()
{
    int test,cs=0;
    cin>>test;

    while(test--)
    {
        init();
        vec.clear();
        memset(edgeTaken,0,sizeof(edgeTaken));

        cin>>node>>edge;

        while(edge--)
        {
            cin>>ed.u>>ed.v>>ed.w;
            vec.push_back(ed);
        }

        sort(vec.begin(),vec.end(),cmp);

        cout<<"Case #"<<++cs<<" : ";

        ans = MST_1(); /// 1st MST

        if(ans == -1) /// edge songkha node-1 na, tai kono vabei MST hbe na..
            cout<<"No way";

        else
        {
            mini = MST_2();

            if(mini == inf)
                cout<<"No second way";
            else
                cout<<mini;
        }

        cout<<endl;
    }

    return 0;
}
