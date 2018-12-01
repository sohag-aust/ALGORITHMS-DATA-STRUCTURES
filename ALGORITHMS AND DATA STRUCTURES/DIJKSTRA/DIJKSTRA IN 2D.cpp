#include<bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int>tii;

const int inf = 1e9;
const int maxi = 1010;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int mat[maxi][maxi];
int cost[maxi][maxi];
int row,col;

void dijkstra(int st,int en)
{
    priority_queue<tii,vector<tii>,greater<tii> >pq;
    fill(&cost[0][0],&cost[maxi][0],inf);

    cost[st][en] = mat[st][en];
    pq.push(tii(cost[st][en],st,en));

    while(!pq.empty())
    {
        int u = get<1>(pq.top());
        int v = get<2>(pq.top());
        int c = get<0>(pq.top());

        if(u == row-1 && v == col-1) return ;

        pq.pop();

        for(int i=0; i<4; i++)
        {
            int uu = u + dx[i];
            int vv = v + dy[i];

            if((uu >= 0 && vv >= 0) && (uu < row && vv < col))
            {
                if(cost[uu][vv] > c + mat[uu][vv])
                {
                    cost[uu][vv] = c + mat[uu][vv];
                    pq.push(tii(cost[uu][vv],uu,vv));
                }
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

    while(test--)
    {
        cin>>row>>col;

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>mat[i][j];

        dijkstra(0,0);

        cout<<cost[row-1][col-1]<<endl;
    }

    return 0;
}

