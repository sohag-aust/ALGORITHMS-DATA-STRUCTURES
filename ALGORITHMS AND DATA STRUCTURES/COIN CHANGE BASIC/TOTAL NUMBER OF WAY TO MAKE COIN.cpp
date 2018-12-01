
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll coins[] = {1,5,10,25,50};

int main()
{
    ll n,track;

    while(cin>>n)
    {
        track = 5;

        if(n == 0)
            cout<<"There is only "<<1<<" way to produce "<<n<<" cents change."<<endl;

        else
        {
            ll dp[6][n+5];

            for(ll i=0; i<5; i++)
            {
                if(coins[i]>n)
                {
                    track = i;
                    break;
                }

                for(ll j=0; j<=n; j++)
                {
                    if(i == 0) dp[i][j] = 1;

                    else
                    {
                        ll i1 = coins[i];

                        if(i1>j) dp[i][j] = dp[i-1][j];

                        else
                        {
                            ll top = dp[i-1][j];
                            ll diff = j-coins[i];
                            ll val = dp[i][diff];

                            dp[i][j] = top+val;
                        }
                    }
                }
            }

            if(dp[track-1][n] == 1)
                cout<<"There is only "<<dp[track-1][n]<<" way to produce "<<n<<" cents change."<<endl;

            else
                cout<<"There are "<<dp[track-1][n]<<" ways to produce "<<n<<" cents change."<<endl;
        }
    }

    return 0;
}

