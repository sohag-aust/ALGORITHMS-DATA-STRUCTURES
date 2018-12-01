
/// TIME LIMIT VERY POOR -> 2.80 sec...

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int dp[55][n+5];

        int poisa[9] = {0,1,5,10,25,50};

        for(int i1=0; i1<=5; i1++)
        {
            int i=poisa[i1];

            for(int j=0; j<=n; j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                    continue;
                }

                else if(i==0)
                {
                    dp[i][j]=0;
                    continue;
                }

                else
                {
                    if(i>j)
                    {
                        dp[i][j]=dp[poisa[i1-1]][j];
                    }

                    else
                    {
                        int up = dp[poisa[i1-1]][j];
                        int pos = j-i;
                        int val = dp[i][pos];

                        dp[i][j] = up+val;
                    }
                }
            }
        }

        /**cout<<"\n DP Table ->> "<<endl;

        for(int i1=0; i1<=5; i1++)
        {
            int i=poisa[i1];

            for(int j=0; j<=n; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/

        cout<<dp[50][n]<<endl;
    }

    return 0;
}
