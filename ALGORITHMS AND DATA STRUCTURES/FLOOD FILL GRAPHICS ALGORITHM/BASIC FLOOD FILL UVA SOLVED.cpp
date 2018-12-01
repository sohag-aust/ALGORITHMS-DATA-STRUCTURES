#include<bits/stdc++.h>
using namespace std;

const int maxi=105;

char grid[maxi][maxi];
int flag[maxi][maxi];
int row,col;

void init()
{
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            flag[i][j]=0;
}

void floodfill(int i,int j)
{
    if(i<0 || j<0 || i>row-1 || j>col-1)
        return ;

    if(grid[i][j]=='w' && flag[i][j]==0)
    {
        flag[i][j]=1;

        floodfill(i,j+1);
        floodfill(i,j-1);
        floodfill(i-1,j);
        floodfill(i+1,j);
        floodfill(i-1,j-1);
        floodfill(i-1,j+1);
        floodfill(i+1,j-1);
        floodfill(i+1,j+1);
    }
}

int main()
{
    while(cin>>row>>col)
    {
        if(!row && !col) break;
        init();
        int cnt=0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>grid[i][j];

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]=='w' && flag[i][j]==0)
                {
                    cnt++;
                    floodfill(i,j);
                }
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}
