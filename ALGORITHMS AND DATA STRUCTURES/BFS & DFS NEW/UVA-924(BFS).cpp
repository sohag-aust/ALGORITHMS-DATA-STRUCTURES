/// PROTI TA LEVEL E KOITA KORE ELEMENT ACE NIRNOI KORA..

#include<bits/stdc++.h>
using namespace std;

#define maxi 2510

vector<int>v[maxi];
int visit[maxi];
int level[maxi];
map<int,int>mp;

void init()
{
    for(int i=0; i<maxi; i++)
        v[i].clear();
}

void bfs(int source)
{
    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));

    queue<int>q;
    q.push(source);
    visit[source] = 1;

    while(!q.empty())
    {
        int frnt = q.front();
        q.pop();

        int sz = v[frnt].size();

        for(int i=0; i<sz; i++)
        {
            int val = v[frnt][i];

            if(!visit[val])
            {
                q.push(val);
                level[val] = level[frnt]+1;
                mp[level[val]]++;
                visit[val] = 1;
            }
        }
    }
}

int main()
{
    int edge;

    while(cin>>edge)
    {
        init();

        for(int i=0; i<edge; i++)
        {
            int n;
            cin>>n;

            while(n--)
            {
                int m;
                cin>>m;

                v[i].push_back(m);
            }
        }

        int test;
        cin>>test;

        while(test--)
        {
            int source;
            cin>>source;

            mp.clear();
            bfs(source);

            int _max = 0;

            int boom_size = 0;
            int boom_day = 0;

            for(int i=1; i<edge; i++)
            {
                if(mp[i] > _max)
                {
                    boom_size = mp[i];
                    boom_day = i;
                    _max = mp[i];
                }
            }

            if(!boom_size)
                cout<<0;

            else
                cout<<boom_size<<" "<<boom_day;

            cout<<endl;
        }
    }

    return 0;
}

