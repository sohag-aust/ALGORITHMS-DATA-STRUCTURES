#include<bits/stdc++.h>
using namespace std;

int dis[10][10];
int parent[10][10];
vector<int>v;

void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                dis[i][j]=0;

            else
                dis[i][j]=1e9;

            parent[i][j]=j;
        }
    }
}

void find_path(int i,int j)
{
    v.push_back(i);

    while(i!=j)
    {
        i=parent[i][j];
        v.push_back(i);
    }

    return ;
}

int main()
{
    int n,e;

    cin>>n>>e;
    init(n);

    while(e--)
    {
        int u,v,w;

        cin>>u>>v>>w;

        dis[u][v]=w;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            // cout<<endl;
            for(int j=1; j<=n; j++)
            {
                //if(i==j) continue;

                //cout<<"i -> "<<i<<endl;
                //cout<<"k -> "<<k<<endl;
                //cout<<"j -> "<<j<<endl;

                //cout<<"\ndis["<<i<<"]["<<k<<"]: "<<dis[i][k]<<endl;
                //cout<<"dis["<<k<<"]["<<j<<"]: "<<dis[k][j]<<endl;
                //cout<<"dis["<<i<<"]["<<j<<"]: "<<dis[i][j]<<endl;


                int sum=dis[i][k] + dis[k][j];
                int temp=dis[i][j];

                //cout<<"sum: "<<sum<<endl;
                //cout<<"temp: "<<temp<<endl;

                if(dis[i][k] + dis[k][j] < dis[i][j])
                {
                    //cout<<"value updated ->> "<<endl;
                    dis[i][j] = dis[i][k] + dis[k][j];
                    parent[i][j]=parent[i][k];
                }

            }
        }
    }

    cout<<"\nMinimum cost for traverse from one to other vertex ->> "<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<endl;
        for(int j=1; j<=n; j++)
        {
            if(i==j)
            {
                cout<<"From "<<i<<" to "<<j<<" the cost is -> "<<dis[i][j]<<endl;
                continue;
            }

            if(dis[i][j]==1e9)
                cout<<"From "<<i<<" to "<<j<<" the cost is -> \"INFINITY\""<<endl;

            else
                cout<<"From "<<i<<" to "<<j<<" the cost is -> "<<dis[i][j]<<endl;
        }
    }


    cout<<"\n\nShortest Path from node to node ->> "<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<endl;
        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;

            find_path(i,j);

            if(dis[i][j]==1e9)
                cout<<"from "<<i<<" to "<<j<<" there is no path.."<<endl;

            else
            {
                cout<<"from "<<i<<" to "<<j<<" path is ->> ";

                for(int i=0; i<v.size(); i++)
                    cout<<v[i]<<" ";
                cout<<endl;
            }


            //cout<<"\n V size: "<<v.size()<<endl;
            v.clear();
        }
    }
}

/**

input:

4 6

2 1 2
4 1 20
3 2 5
1 2 3
2 3 2
4 3 8
*/

