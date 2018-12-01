#include<bits/stdc++.h>
using namespace std;

vector<int>v[100000];
int visit[100000];

void init()
{
    for(int i=0;i<100000;i++)
        v[i].clear();
}

void bfs(int s,int f)
{
    memset(visit,0,sizeof(visit));

    queue<pair<int,int> >q;

    q.push({s,f});
    visit[s] = 1;

    while(!q.empty())
    {
        int frnt_s = q.front().first;
        int frnt_f = q.front().second;

        q.pop();

        int sz = v[frnt_s].size();
        frnt_f--;

        for(int i=0;i<sz;i++)
        {
            int val = v[frnt_s][i];

            if(!visit[val] && frnt_f >=0)
            {
                q.push({val,frnt_f});
                visit[val] = 1;
            }
        }
    }
}

int main()
{
    int edge;
    int cs = 0;

    while(cin>>edge)
    {
        if(!edge) break;

        init();
        set<int>st;

        while(edge--)
        {
            int a,b;
            cin>>a>>b;

            st.insert(a);
            st.insert(b);

            v[a].push_back(b);
            v[b].push_back(a);
        }

        int source,field;

        while(cin>>source>>field)
        {
            if(!source && !field) break;

            bfs(source,field);

            int cnt = 0;

            for(auto i : st)
            {
                if(!visit[i]) cnt++;
            }

            cout<<"Case "<<++cs<<": ";
            cout<<cnt<<" nodes not reachable from node "<<source<<" with TTL = "<<field<<"."<<endl;
        }
    }

    return 0;
}

