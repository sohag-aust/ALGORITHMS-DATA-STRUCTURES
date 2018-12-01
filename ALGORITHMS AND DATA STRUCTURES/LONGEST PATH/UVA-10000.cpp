#include<bits/stdc++.h>
using namespace std;

int adj[110][110];

void init(int node)
{
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            if(i == j)
                adj[i][j] = 0;

            else
                adj[i][j] = INT_MIN;
        }
    }
}

void floyd_warshall(int node)
{
    for(int k=1; k<=node; k++)
    {
        for(int i=1; i<=node; i++)
        {
            for(int j=1; j<=node; j++)
            {
                if(adj[i][k] != INT_MIN && adj[k][j] != INT_MIN) /// jodi ei case na dei tahole (-oshim + -oshim) > -oshim) kono case hole adj[i][j] er moddhe again -oshim e bose jabe.. jar fole real solution pabona....
                {
                    if(adj[i][k] + adj[k][j] > adj[i][j])
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }
}

int main()
{
    int node;
    int cs = 0;

    while(cin>>node && node)
    {
        init(node);

        int start;
        cin>>start;

        int a,b;

        while(cin>>a>>b)
        {
            if(!a && !b) break;
            adj[a][b] = 1;
        }

        floyd_warshall(node);

        int max_length = 0;
        int reach_node = 0;

        for(int i=1; i<=node; i++)
        {
            int length = adj[start][i];

            if(length > max_length)
            {
                max_length = length;
                reach_node = i;
            }
        }

        cout<<"Case "<<++cs<<": ";
        cout<<"The longest path from "<<start<<" has length "<<max_length<<", finishing at "<<reach_node<<"."<<endl;
        cout<<endl;
    }

    return 0;
}

/**
5
3
1 2
3 5
3 1
2 4
4 5
0 0
*/

