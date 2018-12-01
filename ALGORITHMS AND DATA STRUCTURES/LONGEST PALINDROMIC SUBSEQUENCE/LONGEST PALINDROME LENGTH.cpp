#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int test;
    cin>>test;
    cin.ignore();

    while(test--)
    {
        string str;

        getline(cin,str);

        int sz = str.size();

        if(sz == 0)
            cout<<0<<endl;

        else
        {
            int dp[sz+5][sz+5];

            for(int i=1; i<=sz; i++)
                for(int j=0; j<i; j++)
                    dp[i][j] = 0;

            int cnt = 1;
            int i,j;

            i = j = 0;

            while(cnt <= sz)
            {
                if(cnt == 1)
                {
                    if(i==0 && j==0)
                        dp[i][j] = 1;

                    else
                    {
                        if(i+1 <= sz)
                            dp[i][j] = 1 + max(dp[i][j-1],dp[i+1][j]);

                        else
                            dp[i][j] = 1 + dp[i][j-1];
                    }

                    i++,j++;

                    if(i > sz-1 && j > sz-1)
                    {
                        i=0,j=1;
                        cnt++;
                    }
                }

                else
                {
                    if(str[i] == str[j])
                    {
                        dp[i][j] = dp[i+1][j-1] + 2;
                        /// mark i,j as diagonal;
                    }

                    else
                    {
                        int left,bottom;
                        left = bottom = 0;

                        if(j-1 >= 0)
                            left = dp[i][j-1];

                        if(i+1 <= sz)
                            bottom = dp[i+1][j];

                        if(left >= bottom)
                        {
                            dp[i][j] = left;
                            /// mark i,j as left;
                        }

                        else
                        {
                            dp[i][j] = bottom;
                            /// mark i,j as bottom;
                        }
                    }

                    i++,j++;

                    if(i == sz-1 || j == sz)
                    {
                        i=0,j=cnt;
                        cnt++;
                    }
                }
            }

            /// DP TABLE PRINT

            /**for(int i=0;i<sz;i++)
            {
                for(int j=0;j<sz;j++)
                cout<<dp[i][j]<<" ";
                cout<<endl;
            }

            cout<<endl;*/

            cout<<dp[0][sz-1]<<endl;
        }
    }

    return 0;
}

