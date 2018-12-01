#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1="walking";
    string s2="down";

    pair<int,int>p;
    map<pair<int,int> , char>parent;
    vector<char>ans;

    int x=s1.size();
    int y=s2.size();

    int dp[x+2][y+2];

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }

            p=make_pair(i,j);

            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                //p=make_pair(i,j);
                parent[p]='D';
            }

            else
            {
                if(dp[i][j-1]>=dp[i-1][j])
                {
                    dp[i][j]=dp[i][j-1];
                    //p=make_pair(i,j);
                    parent[p]='L';
                }

                else if(dp[i][j-1]<dp[i-1][j])
                {
                    dp[i][j]=dp[i-1][j];
                    //p=make_pair(i,j);
                    parent[p]='U';
                }
            }
        }
    }

    cout<<"\nDP TABLE ->> "<<endl<<endl;

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            p=make_pair(i,j);
            cout<<dp[i][j]<<parent[p]<<"  ";
        }

        cout<<endl;
    }

    cout<<endl<<endl;

    int i=x;
    int j=y;

    while(i && j)
    {
        p=make_pair(i,j);

        if(parent[p]=='L')
            j--;

        else if(parent[p]=='U')
            i--;

        else
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
    }

    cout<<"Maximum length: "<<dp[x][y]<<endl;

    cout<<"\nSequence ->>  ";

    reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++)
        cout<<ans[i];
    cout<<endl;

    return 0;
}
