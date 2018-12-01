/// UVA - 10336 (RANK THE LANGUAGE).

#include<bits/stdc++.h>
using namespace std;

int row,col;

const int maxi=500;
char ch;

bool flag[maxi][maxi];
char grid[maxi][maxi];

struct node
{
    char c;
    int val;
} ara[maxi];

bool cmp(node lhs,node rhs)
{
    if(lhs.val==rhs.val)
        return lhs.c<rhs.c;

    else
        return lhs.val>rhs.val;
}

void floodfill(char ch,int i,int j)
{
    if(i<0 || j<0 || i>row-1 || j>col-1)
        return ;

    if(grid[i][j]==ch && !flag[i][j])
    {
        flag[i][j]=true;

        floodfill(ch,i,j+1);
        floodfill(ch,i,j-1);
        floodfill(ch,i-1,j);
        floodfill(ch,i+1,j);
    }
}

void init()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            flag[i][j]=false;
        }
    }
}

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        static int cs=0;
        cin>>row>>col;
        init();

        map<char,int>mp;
        set<char>st;

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                cin>>grid[i][j];

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                ch = grid[i][j];
                st.insert(ch);

                if(!flag[i][j])
                {
                    mp[ch]++;
                    floodfill(ch,i,j);
                }
            }
        }

        set<char>::iterator it=st.begin();

        int i=0;
        while(it!=st.end())
        {
            ara[i].c=*it;
            ara[i].val=mp[*it];
            it++;
            i++;
        }

        sort(ara,ara+i,cmp);

        cout<<"World #"<<++cs<<"\n";
        for(int j=0; j<i; j++)
            cout<<ara[j].c<<": "<<ara[j].val<<endl;
    }

    return 0;
}
