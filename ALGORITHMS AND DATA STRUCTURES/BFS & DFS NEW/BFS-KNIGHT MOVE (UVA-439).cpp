#include<bits/stdc++.h>
using namespace std;

int dx[] = {-2,-2,+2,+2,-1,-1,+1,+1};
int dy[] = {+1,-1,+1,-1,+2,-2,-2,+2};

int visit[10][10];
int level[10][10];

int bfs(int r1,int c1,int r2,int c2)
{
    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));

    queue<pair<int,int> >q;
    q.push({r1,c1});

    visit[r1][c1] = 1;

    while(!q.empty())
    {
        int frnt_x = q.front().first;
        int frnt_y = q.front().second;

        if(frnt_x == r2 && frnt_y == c2)
        {
            return level[frnt_x][frnt_y];
        }

        q.pop();

        for(int i=0; i<8; i++)
        {
            int tx = frnt_x + dx[i];
            int ty = frnt_y + dy[i];

            if((tx>0 && tx<=8) && (ty>0 && ty<=8) && !visit[tx][ty])
            {
                q.push({tx,ty});
                level[tx][ty] = level[frnt_x][frnt_y] + 1;
                visit[tx][ty] = 1;
            }
        }
    }
}

int main()
{
    string s1,s2;

    while(cin>>s1>>s2)
    {
        int r1 = s1[0]-96;
        int c1 = s1[1]-48;
        int r2 = s2[0]-96;
        int c2 = s2[1]-48;

        int res = bfs(r1,c1,r2,c2);

        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<res<<" knight moves."<<endl;
    }

    return 0;
}

