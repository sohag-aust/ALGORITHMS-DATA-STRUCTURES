#include<bits/stdc++.h>
using namespace std;

#define maxi 10000

vector<int>v[maxi];
int parent[maxi];
int visit[maxi];
map<string,int>mp1;
map<int,string>mp2;
vector<int>ans;

void init()
{
    for(int i=0; i<maxi; i++)
        v[i].clear();

    mp1.clear();
    mp2.clear();

    memset(visit,0,sizeof(visit));
    memset(parent,0,sizeof(parent));
    ans.clear();
}

void path(int b)
{
    if(parent[b] != b)
    {
        path(parent[b]);
    }

    if(!visit[b])
    {
        if(parent[b] == b)
        {
            visit[b] = 1;
            return ;
        }

        ans.push_back(b);
        visit[parent[b]] = 1;
    }
}

void bfs(int a,int b)
{
    memset(visit,0,sizeof(visit));
    memset(parent,0,sizeof(parent));

    queue<int>q;
    q.push(a);
    visit[a] = 1;

    while(!q.empty())
    {
        int frnt = q.front();
        q.pop();

        int sz = v[frnt].size();

        for(int i=0; i<sz; i++)
        {
            int rear = v[frnt][i];

            if(!visit[rear])
            {
                visit[rear] = 1;
                q.push(rear);
                parent[rear] = frnt;
            }
        }
    }

    memset(visit,0,sizeof(visit));
    ans.clear();
    path(b);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int test;

    cin>>test;
    cin.ignore();

    while(test--)
    {
        init();

        int edge;
        int query;

        cin>>edge>>query;

        int k = 0;

        while(edge--)
        {
            string a,b;
            cin>>a>>b;

            if(!mp1[a])
            {
                mp1[a] = ++k;
                mp2[k] = a;
            }

            if(!mp1[b])
            {
                mp1[b] = ++k;
                mp2[k] = b;
            }

            v[mp1[a]].push_back(mp1[b]);
            v[mp1[b]].push_back(mp1[a]);
        }

        while(query--)
        {
            string a,b;
            cin>>a>>b;

            bfs(mp1[a],mp1[b]);

            for(auto i : ans)
            {
                string temp = mp2[i];
                cout<<temp[0];
            }

            cout<<endl;
        }

        if(test) cout<<endl;
    }

    return 0;
}

