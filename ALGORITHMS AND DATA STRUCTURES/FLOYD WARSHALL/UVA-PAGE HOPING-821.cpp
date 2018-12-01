#include<bits/stdc++.h>
using namespace std;

bool visit[102];

int main()
{
    set<int>st;
    int u,v;

    while(cin>>u>>v)
    {
        static int cnt=1;

        int dis[102][102];

        for(int i=1; i<=100; i++)
        {
            for(int j=1; j<=100; j++)
            {
                if(i==j)
                    dis[i][j]=0;

                else
                    dis[i][j]=1000;
            }
        }

        if(!u && !v) return 0;

        st.insert(u);
        st.insert(v);

        dis[u][v]=1;

        visit[u]=true;
        visit[v]=true;

        while(cin>>u>>v)
        {
            if(!u && !v) break;

            visit[u]=true;
            visit[v]=true;

            dis[u][v]=1;
            st.insert(u);
            st.insert(v);
        }

        set<int>::iterator it;
        it=st.begin();
        int val1=*it;

        int val2;

        while(it!=st.end())
        {
            val2=*it;
            it++;
        }

        int si=st.size();

        int mini=val1;
        int maxi=val2;

        int sum=0;
        int node=si*(si-1);

        for(int k=mini; k<=maxi; k++)
        {
            for(int i=mini; i<=maxi; i++)
            {
                for(int j=mini; j<=maxi; j++)
                {
                    if(visit[i] && visit[j])
                    {
                        if(dis[i][k]+dis[k][j] < dis[i][j])
                        {
                            dis[i][j]=dis[i][k]+dis[k][j];
                        }
                    }
                }
            }
        }

        for(int i=mini; i<=maxi; i++)
        {
            for(int j=mini; j<=maxi; j++)
            {
                if(visit[i] && visit[j])
                    sum+=dis[i][j];
            }
        }

        double ans=(double)sum/(double)node;

        printf("Case %d: average length between pages = %.3lf clicks\n",cnt,ans);
        cnt++;

        st.clear();
        memset(visit,false,sizeof(visit));
    }

    return 0;
}
