#include<bits/stdc++.h>
using namespace std;

#define maxi 10000

vector<int>v[maxi];
int visit[maxi];
int start,eend;

void init()
{
    memset(visit,0,sizeof(visit));

    for(int i=0; i<maxi; i++)
        v[i].clear();
}

void dfs(int i)
{
    int sz = v[i].size();

    for(int j=0; j<sz; j++)
    {
        int frnt = v[i][j];

        if(!visit[frnt])
        {
            visit[frnt] = 1;
            dfs(frnt);
        }
    }
}

int main()
{
    int node;

    while(cin>>node)
    {
        init();

        if(!node) break;

        while(cin>>start && start)
        {
            while(cin>>eend && eend)
            {
                v[start].push_back(eend);
            }
        }

        int query;

        cin>>query;

        while(query--)
        {
            int n;
            cin>>n;

            memset(visit,0,sizeof(visit));
            dfs(n);

            vector<int>ans;

            for(int i=1; i<=node; i++)
            {
                if(!visit[i])
                {
                    ans.push_back(i);
                }
            }

            if(ans.size() == 0) cout<<"0";

            else
            {
                cout<<ans.size()<<" ";

                for(int i=0; i<ans.size(); i++)
                {
                    if(i == ans.size()-1) cout<<ans[i];
                    else cout<<ans[i]<<" ";
                }
            }

            cout<<endl;
        }
    }

    return 0;
}

