/// TUTORIAL -> https://www.youtube.com/watch?v=g8bSdXCG-lA

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    cin.ignore();
    cin.ignore();

    while(test--)
    {
        string str;
        int temp[30];
        memset(temp,0,sizeof(temp));

        int maxi = 0;

        while(getline(cin,str))
        {
            int mini = 1e9,cnt = 0;
            if(str.length() == 0) break;
            int sz = str.size();

            for(int i=0; i<sz; i++)
            {
                int val = str[i]-'0';

                if(val) temp[i] += val;
                else temp[i] = 0;

                val = temp[i];

                if(val)
                {
                    cnt++;
                    mini = min(mini,val);
                }

                else
                {
                    maxi = max(maxi,mini*cnt);
                    cnt = 0, mini = 1e9;
                }
            }

            maxi = max(maxi,mini*cnt);
        }

        cout<<maxi<<endl;
        if(test) cout<<endl;
    }

    return 0;
}
