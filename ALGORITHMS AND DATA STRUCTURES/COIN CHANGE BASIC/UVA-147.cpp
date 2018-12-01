#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n,track;
    ll a,b;

    while(scanf("%lld.%lld",&a,&b))
    {
        n=a*100+b;

        if (n==0) break;

        track = 11;

        ll dp[12][n+5];

        for(ll i=0; i<11; i++)
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

        printf("%3lld.%.2lld%17ld\n",a,b,dp[track-1][n]);
    }

    return 0;
}
