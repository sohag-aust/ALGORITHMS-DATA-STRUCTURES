#include<bits/stdc++.h>
using namespace std;

char ch[35][85];
int flag[35][85];
int n,k;

map<int,int>mp;

int dx[]= {-1,0,+1,-1,+1,-1,0,+1};
int dy[]= {-1,-1,-1,0,0,+1,+1,+1};

void floodfill(int i,int j)
{
    if(i<0 || j<0 || i>n-1 || j>mp[i]-1)
        return ;

    if(ch[i][j]=='X') return ;

    if( (ch[i][j]=='#' || ch[i][j]=='*' || ch[i][j]==' ') && flag[i][j]==0 )
    {
        ch[i][j]='#';
        flag[i][j]=1;

        for(int m=0; m<8; m++)
        {
            int x=i+dx[m];
            int y=j+dy[m];

            if( (ch[x][y]=='#' || ch[x][y]=='*' || ch[x][y]==' ') )
                floodfill(x,y);
        }
    }
}

int main()
{
    int test;
    cin>>test;
    cin.ignore();

    while(test--)
    {
        memset(ch,'\0',sizeof(ch));
        memset(flag,0,sizeof(flag));

        mp.clear();

        n=0,k=0;

        while(gets(ch[n]))
        {
            k=0;
            for(int i=0; ch[n][i]; i++)
                k++;

            mp[n]=k;

            if(ch[n][0]=='_') break;
            n++;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; ch[i][j]; j++)
            {
                if(ch[i][j]=='*' && flag[i][j]==0)
                {
                    floodfill(i,j);
                }
            }
        }

        for(int i=0; i<=n; i++)
            puts(ch[i]);
    }

    return 0;
}

