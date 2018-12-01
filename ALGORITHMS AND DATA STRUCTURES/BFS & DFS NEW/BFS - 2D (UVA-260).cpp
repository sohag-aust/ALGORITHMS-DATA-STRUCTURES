#include<bits/stdc++.h>
using namespace std;

#define maxi 210

int dx[]= {0,0,1,-1,1,-1};
int dy[]= {1,-1,0,0,1,-1};

char grid[maxi][maxi];
int visit[maxi][maxi];
int row,col;
int sx,sy;

void bfs(int sx,int sy)
{
    visit[sx][sy] = 1;

    queue<pair<int,int> >q;
    q.push({sx,sy});

    while(!q.empty())
    {
        int frnt_x = q.front().first; /// row
        int frnt_y = q.front().second; /// col

        q.pop();

        for(int i=0; i<6; i++)
        {
            int tx = frnt_x + dx[i];
            int ty = frnt_y + dy[i];

            if((tx>=0 && tx<row) && (ty>=0 && ty<col) && (grid[tx][ty] == 'b') && (!visit[tx][ty]))
            {
                q.push({tx,ty});
                visit[tx][ty] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int sz;

    while(cin>>sz)
    {
        static int cs = 0;

        if(!sz) break;

        memset(grid,'\0',sizeof(grid));
        memset(visit,0,sizeof(visit));

        row = sz;
        col = sz;

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>grid[i][j];

        for(int i=0; i<col; i++)
        {
            if(grid[0][i] == 'b' && !visit[0][i])
            {
                bfs(0,i); /// first row er protita column teheke bfs calaici jekhane 'b' ace.
            }
        }

        string res = "";

        for(int i=0; i<col; i++)
        {
            if(visit[row-1][i]) /// jodi last row er jekono column e visit array 1 return kore tar mane se last row te pouchaice mane sob row tei pouchaice.
            {
                res = "B";
                break;
            }
        }

        cout<<++cs<<" ";

        if(!res.empty()) cout<<res;
        else cout<<"W";

        cout<<endl;
    }

    return 0;
}

