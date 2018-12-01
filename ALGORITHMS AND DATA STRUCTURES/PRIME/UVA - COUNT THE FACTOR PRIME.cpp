#include<bits/stdc++.h>
using namespace std;

const int maxi=1000000;
vector<int>v;
map<int,int>visit;

void seive()
{
    visit.clear();
    for(int i=3;i*i<=maxi;i+=2)
    {
        if(!visit[i])
        {
            for(int j=i*i;j<=maxi;j+=i)
                visit[j]=true;
        }
    }

    v.push_back(2);
    for(int i=3;i<=maxi;i+=2)
    {
        if(!visit[i])
            v.push_back(i);
    }
}

int main()
{
    seive();

    int n;
    while(cin>>n)
    {
        if(!n) break;

        int cnt=0;

        for(int i=0;i<v.size();i++)
        {
            if(v[i]>n) break;

            if(n%v[i]==0)
                cnt++;
        }

        cout<<n<<" : "<<cnt<<endl;
    }

    return 0;
}
