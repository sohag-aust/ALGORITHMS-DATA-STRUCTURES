#include<bits/stdc++.h>
using namespace std;

int visit[30][30],row,cnt,col;
char grid[30][30];

void floodfill(int i,int j,char ch)
{
    if(i<0 || j<0 || i>row-1 || j>col-1)
        return ;

    if(grid[i][j]==ch && !visit[i][j])
    {
        visit[i][j]=1;

        if(ch=='1')
            cnt++;

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
    int test;
    cin>>test;
    cin.ignore();
    cin.ignore();

    while(test--)
    {
        memset(visit,0,sizeof(visit));
        string str;
        vector<string>v;
        int maxi=0,value=0;

        while(getline(cin,str))
        {
            if(str.size()==0) break;
            v.push_back(str);
        }

        row=v.size();

        for(int i=0; i<row; i++)
        {
            string s=v[i];
            col=s.size();

            for(int j=0; j<col; j++)
                grid[i][j]=s[j];
        }

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]=='1' && !visit[i][j])
                {
                    cnt=0;
                    floodfill(i,j,'1');

                    if(cnt>maxi)
                        maxi=cnt;
                }
            }
        }

        cout<<maxi<<endl;
        if(test) cout<<endl;
    }

    return 0;
}
