#include<bits/stdc++.h>
using namespace std;

#define maxi 1010

int dx[] = {0,0,-1,+1};
int dy[] = {-1,+1,0,0};

int level[maxi][maxi];
int visit[maxi][maxi];
int grid[maxi][maxi];

int row,col;
int sx,sy;
int ex,ey;

int bfs(int sx,int sy)
{
    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));

    visit[sx][sy] = 1;

    queue<pair<int,int> >q;

    q.push({sx,sy});

    while(!q.empty())
    {
        int frnt_x = q.front().first;
        int frnt_y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++)
        {
            int tx = frnt_x + dx[i];
            int ty = frnt_y + dy[i];

            if( (tx>=0 && tx<row) && (ty>=0 && ty<col) && (grid[tx][ty] != -1) && (!visit[tx][ty]) )
            {
                q.push({tx,ty});
                level[tx][ty] = level[frnt_x][frnt_y] + 1;
                visit[tx][ty] = 1;

                if(tx == ex && ty == ey)
                {
                    return level[tx][ty];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    while(cin>>row>>col)
    {
        memset(grid,0,sizeof(grid));

        if(!row && !col) break;

        int line;

        cin>>line;

        while(line--)
        {
            int row_number;
            cin>>row_number;

            int n;
            cin>>n;

            while(n--)
            {
                int col_number;
                cin>>col_number;

                grid[row_number][col_number] = -1;
            }
        }

        cin>>sx>>sy;
        cin>>ex>>ey;

        int res = bfs(sx,sy);

        cout<<res<<endl;
    }

    return 0;
}

