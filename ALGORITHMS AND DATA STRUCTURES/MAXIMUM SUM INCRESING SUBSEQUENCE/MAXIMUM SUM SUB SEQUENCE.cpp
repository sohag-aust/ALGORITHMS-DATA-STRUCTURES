#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin>>n;

    int ara[n+2];
    int temp_ara[n+2];
    int sequence[n+2];

    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
        temp_ara[i] = ara[i];
        sequence[i] = i;
    }

    int sum = 0;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(ara[j] < ara[i])
            {
                sum = temp_ara[j] + ara[i];

                if(sum > temp_ara[i])
                {
                    temp_ara[i] = sum;
                    sequence[i] = j;
                }
            }
        }
    }

    int maxi = temp_ara[0];
    int index = 0;

    for(int i=1; i<n; i++)
    {
        if(maxi < temp_ara[i])
        {
            maxi = temp_ara[i];
            index = i;
        }
    }


    cout<<"\nMaximum Sum: "<<maxi<<endl;

    vector<int>v;
    map<int,int>mp;

    cout<<"\nSequence Array -> "<<endl;

    while(index >= 0)
    {
        mp[index]++;
        if(mp[index]>1) break;

        v.push_back(ara[index]);
        index = sequence[index];
    }

    reverse(v.begin(),v.end());

    for(auto it : v)
        cout<<it<<" ";
    cout<<endl;

    return 0;
}
/**
7
4 6 1 3 8 4 6

7
1 101 2 3 100 4 5
*/

