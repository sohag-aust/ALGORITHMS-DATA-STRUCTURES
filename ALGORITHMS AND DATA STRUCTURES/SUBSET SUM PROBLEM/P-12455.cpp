#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int knap_size;
    int object_size;
    int test;

    cin>>test;

    while(test--)
    {
        cin>>knap_size;
        cin>>object_size;

        int object_ara[object_size + 5];

        char dp[object_size+2][knap_size+2];
        string direction[object_size+2][knap_size+2];

        for(int i=0; i<object_size ; i++)
            cin>>object_ara[i];

        for(int i=0; i<object_size; i++)
        {
            for(int j=0; j<1; j++)
                dp[i][j] = 'T';
        }

        for(int i=0; i<object_size; i++)
        {
            for(int j=1; j<=knap_size; j++)
            {
                if(i == 0)
                {
                    int val = object_ara[i];

                    if(val == j)
                        dp[i][j] = 'T';
                    else
                        dp[i][j] = 'F';

                    direction[i][j] = "NOTHING";
                }

                else
                {
                    int val = object_ara[i];

                    if(val > j)
                    {
                        dp[i][j] = dp[i-1][j];
                        direction[i][j] = "TOP";
                    }

                    else
                    {
                        if(dp[i-1][j] == 'T')
                        {
                            dp[i][j] = dp[i-1][j];
                            direction[i][j] = "TOP";
                        }

                        else
                        {
                            dp[i][j] = dp[i-1][j-val];
                            direction[i][j] = "TOP";
                        }
                    }
                }
            }
        }

        int i = object_size-1;
        int j = knap_size;

        if(dp[i][j] == 'T')
            cout<<"YES";

        else
            cout<<"NO";

        cout<<endl;
    }

    return 0;
}

