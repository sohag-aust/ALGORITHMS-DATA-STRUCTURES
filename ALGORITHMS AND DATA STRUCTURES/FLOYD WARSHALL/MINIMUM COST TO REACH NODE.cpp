#include<bits/stdc++.h>
using namespace std;

#define sz 25

int dis[sz+5][sz+5];
map<int,string>mp1;

void init(int n)
{
    memset(dis,0,sizeof(dis));
    mp1.clear();

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                dis[i][j] = 0;

            else
                dis[i][j] = 1e9;
        }
    }
}

int main()
{
    int n,e;
    int cs = 0;

    while(cin>>n>>e,n)
    {
        init(n);

        for(int i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            mp1[i] = str;
        }

        while(e--)
        {
            int u,v,w;
            cin>>u>>v>>w;

            dis[u][v] = w;
            dis[v][u] = w;
        }

        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(dis[i][k] + dis[k][j] < dis[i][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        int mini = 1e9;
        int sum = 0,node = 0;

        for(int i=1; i<=n; i++)
        {
            sum = 0;

            for(int j=1; j<=n; j++)
            {
                if(i != j)
                {
                    sum += dis[i][j];
                }
            }

            if(mini > sum)
            {
                mini = sum;
                node = i;
            }
        }

        cout<<"Case #"<<++cs<<" : "<<mp1[node]<<endl;
    }

    return 0;
}

