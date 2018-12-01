#include<bits/stdc++.h>
using namespace std;

#define MAX 15

int cost[MAX][MAX];
int path[MAX][MAX];
int mat[MAX],sz;

void CLR()
{
    memset(cost,0,sizeof(cost));
    memset(path,0,sizeof(path));
    memset(mat,0,sizeof(mat));
}

void MCM()
{
    for(int l=2; l<=sz; l++)
    {
        for(int i=1,j=(i+l-1); i<=(sz-l+1); i++,j++)
        {
            cost[ i ][ j ] = INT_MAX;

            for(int k=i; k<=j-1; k++)
            {
                int mat_cost = cost[i][k] + cost[k+1][j] + (mat[i-1] * mat[k] * mat[j]);

                if(mat_cost < cost[i][j])
                {
                    cost[i][j] = mat_cost;
                    path[i][j] = k;
                }
            }
        }
    }
}

void OPTIMAL_ORDER(int i,int j)
{
    if(i == j)
    {
        cout<<"A"<<i;
        return ;
    }

    else
    {
        cout<<"(";
        OPTIMAL_ORDER(i,path[i][j]);
        cout<<" x ";
        OPTIMAL_ORDER(path[i][j]+1,j);
        cout<<")";
    }
}

int main()
{
    while(cin>>sz && sz)
    {
        static int cs = 0;

        for(int i=1; i<=sz; i++)
        {
            cin>>mat[i-1]>>mat[i];
        }

        MCM();
        cout<<"Case "<<++cs<<": ";
        OPTIMAL_ORDER(1,sz);
        cout<<endl;

        cout<<"OPTIMAL cost: "<<cost[1][sz]<<endl;

        CLR();
    }

    return 0;
}

