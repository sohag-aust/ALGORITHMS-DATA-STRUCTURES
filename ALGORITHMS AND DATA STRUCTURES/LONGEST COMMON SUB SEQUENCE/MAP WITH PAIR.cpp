#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,int>p;
    map<int,pair<int,int> >mp;

    int cnt=0;

    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            p=make_pair(i,j);
            mp[cnt]=p;
            cnt++;
        }
    }

    for(int i=0;i<cnt;i++)
        cout<<mp[i].first<<"  "<<mp[i].second<<" \n";

    return 0;
}
