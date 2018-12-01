/// Coin Change
/// 0 theke 5 porjonto poisa die 5 taka banate total koi vabe banano jabe.??

/**

Rules: if r>c then just copy the value from above cell
       else dp[i][j] = value of above cell + value of(dp[i][j-i])

*/

#include<bits/stdc++.h>
using namespace std;

/// input : 5 5

int main()
{
    int koto_porjonto,koto_taka;
    cin>>koto_porjonto>>koto_taka;

    int row = koto_porjonto;
    int col = koto_taka;

    int dp[row+5][col+5];

    for(int i=0; i<=row; i++)
    {
        for(int j=0; j<=col; j++)
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
                    dp[i][j]=dp[i-1][j];
                }

                else
                {
                    int up = dp[i-1][j];
                    int pos = j-i;
                    int val = dp[i][pos];

                    dp[i][j] = up+val;
                }
            }
        }
    }

    cout<<"\n DP Table ->> "<<endl;

    for(int i=0; i<=row; i++)
    {
        for(int j=0; j<=col; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

