#include<bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int>tii;
#define sz 25

vector<tuple<int,int,int> >v;
char grid[sz][sz],ch;
int flag[sz][sz];
int suru,sesh,cnt = 0;
int row,col;

void floodfill(int i,int j,int p)
{
    if(j == row)
        j = 0;
    else if(j == -1)
        j = row-1;

    if(i<0 || j<0 || i>row-1 || j>col-1)
        return ;

    if(grid[i][j] == ch && !flag[i][j])
    {
        cnt++;
        flag[i][j] = 1;

        floodfill(i,j+1,p);
        floodfill(i,j-1,p);
        floodfill(i-1,j,p);
        floodfill(i+1,j,p);
    }
}

int main()
{
    while(cin>>row>>col)
    {
        fill(&grid[0][0],&grid[row][0],'\0');

        for(int i=0; i<row; i++)
        {
             for(int j=0; j<col; j++)
             {
                 cin>>grid[i][j];
                 grid[i][j] = tolower(grid[i][j]);
             }
        }

        fill(&flag[0][0],&flag[row][0],0);

        cin>>suru>>sesh;
        ch = grid[suru][sesh];

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == ch)
                {
                    if(i == suru && j == sesh)
                    {
                        v.push_back(tii(i,j,0));
                        floodfill(i,j,0);
                    }

                    else
                        v.push_back(tii(i,j,1));
                }
            }
        }

        int maxi = 0;

        for(auto &x : v)
        {
            int i = get<0>(x);
            int j = get<1>(x);
            int p = get<2>(x);

            if(!flag[i][j] && p)
            {
                cnt = 0;
                floodfill(i,j,p);
                maxi = max(maxi,cnt);
            }
        }

        cout<<maxi<<endl;

        v.clear();
        cin.ignore();
    }

    return 0;
}
