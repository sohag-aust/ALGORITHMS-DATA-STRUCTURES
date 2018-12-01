#include<bits/stdc++.h>
using namespace std;

#define maxi 210

vector<int>vv[maxi];
vector<string>v[maxi];
map<string,int>mp;
int visit[maxi];
int level[maxi];

void CLR()
{
    for(int i=0;i<maxi;i++)
    {
        vv[i].clear();
        v[i].clear();
    }

    mp.clear();
    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));
}

int bfs(string source,string destination)
{
    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));

    queue<int>q;
    q.push(mp[source]);
    visit[mp[source]] = 1;

    while(!q.empty())
    {
        int frnt = q.front();
        q.pop();

        if(frnt == mp[destination])
            return level[frnt];

        int sz = vv[frnt].size();

        for(int i=0; i<sz; i++)
        {
            int val = vv[frnt][i];

            if(!visit[val])
            {
                q.push(val);
                level[val] = level[frnt]+1;
                visit[val] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin>>test;
    cin.ignore();

    while(test--)
    {
        CLR();

        string str;
        int cs = 0;

        while(cin>>str)
        {
            if(str == "*") break;

            if(mp[str] == 0)
            {
                mp[str] = ++cs;
            }

            int len = str.size();

            v[len].push_back(str);
        }

        string source,destination;
        string line,s;

        cin.ignore();

        while(getline(cin,line))
        {
            source = destination = "";
            vector<string>store;

            if(line.size() == 0)
            {
                if(test) cout<<endl;
                break;
            }

            stringstream ss(line);

            while(ss>>s)
            {
                store.push_back(s);
            }

            source = store[0];
            destination = store[1];

            int i = source.size();
            int sz = v[i].size();

            int k1 = 0;

            while(k1<sz)
            {
                string init = v[i][k1];

                for(int j=0; j<sz; j++)
                {
                    string temp = v[i][j];

                    int cnt = 0;

                    for(int k=0; k<i; k++)
                    {
                        if(init[k] != temp[k])
                        {
                            cnt++;
                        }
                    }

                    if(cnt == 1)
                    {
                        vv[mp[init]].push_back(mp[temp]);
                    }
                }

                k1++;
            }

            int res = bfs(source,destination);

            cout<<source<<" "<<destination<<" "<<res<<endl;
        }
    }

    return 0;
}

