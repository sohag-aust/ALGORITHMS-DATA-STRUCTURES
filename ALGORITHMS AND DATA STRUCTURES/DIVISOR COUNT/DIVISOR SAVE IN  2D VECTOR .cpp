#include<bits/stdc++.h>
using namespace std;

const int maxi=5*100002;
vector<int>v[maxi];

void pre()
{
    for(int i=1;i<=maxi;i++)
    {
        for(int j=i;j<=maxi;j+=i)
        {
            v[j].push_back(i);
        }
    }
}

int main()
{
    pre();
    int n,k,test;
    cin>>test;

    while(test--)
    {
        int sum=0;
        cin>>n>>k;
        int si=v[n].size();

        for(int i=0;i<si;i++)
        {
            int val=v[n][i];
            if(val%k!=0)
                sum+=val;
        }

        cout<<sum<<endl;
    }

    return 0;
}
