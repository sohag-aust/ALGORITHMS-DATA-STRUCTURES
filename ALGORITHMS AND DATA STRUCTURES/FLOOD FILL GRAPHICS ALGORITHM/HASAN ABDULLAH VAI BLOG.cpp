#include<bits/stdc++.h>
using namespace std;

const int maxi=105;

char grid[maxi][maxi];
int flag[maxi][maxi];
int row,col;
int cg=0,cr=0,cb=0;

void init()
{
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            flag[i][j]=0;
}

void floodfill(int i,int j, char ch)
{
    if(i<0 || j<0 || i>row-1 || j>col-1)
        return ;

    if(grid[i][j]==ch && flag[i][j]==0)
    {
        flag[i][j]=1;
        if(ch == 'R') cr++;
        if(ch == 'G') cg++;
        if(ch == 'B') cb++;

        floodfill(i,j+1,ch);
        floodfill(i,j-1,ch);
        floodfill(i-1,j,ch);
        floodfill(i+1,j,ch);
        floodfill(i-1,j-1,ch);
        floodfill(i-1,j+1,ch);
        floodfill(i+1,j-1,ch);
        floodfill(i+1,j+1,ch);
    }
}

int main()
{
    while(cin>>row>>col)
    {
        if(!row && !col) break;
        init();
        int r,g,b;
        r=g=b=0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>grid[i][j];

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]=='R' && flag[i][j]==0)
                {
                    r++;
                    floodfill(i,j,'R');
                }
                if(grid[i][j]=='G' && flag[i][j]==0)
                {
                    g++;
                    floodfill(i,j,'G');
                }
                if(grid[i][j]=='B' && flag[i][j]==0)
                {
                    b++;
                    floodfill(i,j,'B');
                }
            }
        }

        cout<<"R - "<<r<<" region - "<<cr<<" pixel"<<endl;
        cout<<"G - "<<g<<" region - "<<cg<<" pixel"<<endl;
        cout<<"B - "<<b<<" region - "<<cb<<" pixel"<<endl;
    }

    return 0;
}
