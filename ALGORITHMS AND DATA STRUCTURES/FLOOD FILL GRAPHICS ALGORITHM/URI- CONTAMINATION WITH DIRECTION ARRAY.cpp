#include<bits/stdc++.h>
using namespace std;

const int maxi=55;
char grid[maxi][maxi];
int flag[maxi][maxi];
int r,c;

int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};

void init()
{
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            flag[i][j]=0;
}

void floodfill(int i,int j)
{
    if(i<0 || j<0 || i>r-1 || j>c-1)
        return ;

    if(grid[i][j]=='X')
        return ;

    if(grid[i][j]=='A' && flag[i][j]==0)
    {
        grid[i][j]='T';
        flag[i][j]=1;

        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if(grid[x][y]=='A')
                floodfill(x,y);
        }
    }
}

int main()
{
    while(cin>>r>>c)
    {
        init();
        if(!r && !c) break;

        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin>>grid[i][j];

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]=='T' && flag[i][j]==0)
                {
                    if(grid[i-1][j]=='A' && flag[i-1][j]==0)
                        floodfill(i-1,j);

                    if(grid[i+1][j]=='A' && flag[i+1][j]==0)
                        floodfill(i+1,j);

                    if(grid[i][j-1]=='A' && flag[i][j-1]==0)
                        floodfill(i,j-1);

                    if(grid[i][j+1]=='A' && flag[i][j+1]==0)
                        floodfill(i,j+1);
                }
            }
        }

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
                cout<<grid[i][j];
            cout<<endl;
        }

        cout<<endl;
    }

    return 0;
}

