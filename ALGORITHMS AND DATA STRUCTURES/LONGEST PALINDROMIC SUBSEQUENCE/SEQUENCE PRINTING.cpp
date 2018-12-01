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

        int dp[sz+5][sz+5];
        string direction[sz+5][sz+5];

        if(sz == 0)
            cout<<0<<endl;

        else
        {
            for(int i=1; i<=sz; i++)
            {
                for(int j=0; j<i; j++)
                {
                    dp[i][j] = 0;
                    direction[i][j] = "NOTHING";
                }
            }

            int cnt = 1;
            int i,j;

            i = j = 0;

            while(cnt <= sz)
            {
                if(cnt == 1)
                {
                    if(i==0 && j==0)
                    {
                        dp[i][j] = 1;
                        direction[i][j] = "NOTHING";
                    }


                    else
                    {
                        if(i+1 <= sz)
                        {
                            if(str[i] == str[j])
                            {
                                dp[i][j] = dp[i+1][j-1] + 1;
                                direction[i][j] = "DIAGONAL";
                            }

                            else if(dp[i][j-1] >= dp[i+1][j])
                            {
                                dp[i][j] = 1 + dp[i][j-1];
                                direction[i][j] = "LEFT";
                            }

                            else
                            {
                                dp[i][j] = 1+ dp[i+1][j];
                                direction[i][j] = "BOTTOM";
                            }
                        }

                        else
                        {
                            dp[i][j] = 1 + dp[i][j-1];
                            direction[i][j] = "BOTTOM";
                        }
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
                        direction[i][j] = "DIAGONAL";
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
                            direction[i][j] = "LEFT";
                        }

                        else
                        {
                            dp[i][j] = bottom;
                            direction[i][j] = "BOTTOM";
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

            cout<<"\nLENGTH OF THE LONGEST PALINDROME: ";

            cout<<dp[0][sz-1]<<endl;
        }

        int i,j;

        i = 0;
        j = sz-1;

        vector<char>v;

        while(j>=0)
        {
            if(direction[i][j] == "STOP")
                break;

            else if(direction[i][j] == "DIAGONAL")
            {
                v.push_back(str[i]);
                i++,j--;
            }

            else
            {
                if(direction[i][j] == "NOTHING" || direction[i][j] == "LEFT")
                    j--;

                else
                    i++;
            }
        }

        cout<<endl;
        cout<<"Longest Palindromic Sequence is: ";

        /** SOLUTION TABLE PRINT

        for(int i=0; i<sz; i++)
        {
            for(int j=0; j<sz; j++)
                cout<<direction[i][j]<<"  ";
            cout<<endl;
        }*/

        for(auto it : v)
            cout<<it;

        reverse(v.begin(),v.end());

        if(dp[0][sz-1] & 1)
        {
            for(int i=1; i<v.size(); i++)
                cout<<v[i];
        }

        else
        {
            for(auto it : v)
                cout<<it;
        }

        cout<<endl;
    }

    return 0;
}


