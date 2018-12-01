#include<bits/stdc++.h>
#define pii pair<int, int>
#define clear(a) memset(a, 0, sizeof(a))

using namespace std;

int fx[]= {1, -1, 1, -1, 2, 2, -2, -2};
int fy[]= {2, 2, -2, -2, 1, -1, 1, -1};

string str1, str2;

bool visited[10][10];
int cost[10][10];

void bfs(int a, int b, int c, int d)
{
    queue<pii>q;
    clear(visited);
    q.push(pii(a,b));
    visited[a][b]=true;
    cost[a][b]=0;
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        if(top.first==c && top.second==d)
        {
            cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<cost[top.first][top.second]<<" knight moves.\n";
            return;
        }

        for(int i=0; i<8; i++)
        {
            int f = top.first + fx[i];
            int s = top.second + fy[i];

            if((f>0 && f<=8) && (s>0 && s<=8) && !visited[f][s] )
            {
                visited[f][s] = true;
                cost[f][s]=cost[top.first][top.second]+1;
                q.push(pii(f,s));
            }
        }
    }
}

int main()
{
    while(cin>>str1>>str2)
    {
        int sx = str1[0] - 96;
        int sy = str1[1] - '0';
        int dx = str2[0] - 96;
        int dy = str2[1] - '0';

        bfs(sx,sy,dx,dy);
    }

    return 0;
}

