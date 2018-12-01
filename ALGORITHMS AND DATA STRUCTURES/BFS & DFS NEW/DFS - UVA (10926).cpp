#include<bits/stdc++.h>
using namespace std;

#define sz 110

vector<int>v[sz];
int visit[sz];
int cnt;

void init()
{
    memset(visit,0,sizeof(visit));

    for(int i=0; i<sz; i++)
        v[i].clear();
}

int dfs(int i)
{
    if(!visit[i])
    {
        cnt++;
        visit[i] = 1;
    }

    int _sz = v[i].size();

    for(int j=0; j<_sz; j++)
    {
        int _val = v[i][j];

        if(!visit[_val])
            dfs(_val);
    }

    return cnt;
}

int main()
{
    int n;

    while(cin>>n,n)
    {
        init();

        for(int i=1; i<=n; i++)
        {
            int t;
            cin>>t;

            while(t--)
            {
                int val;
                cin>>val;
                v[i].push_back(val);
            }
        }

        int index = 1;
        int maxi = 0;

        for(int i=1; i<=n; i++)
        {
            memset(visit,0,sizeof(visit));

            cnt = 0;
            int ans = dfs(i);

            if(maxi < ans)
            {
                maxi = ans;
                index = i;
            }
        }

        cout<<index<<endl;
    }

    return 0;
}

