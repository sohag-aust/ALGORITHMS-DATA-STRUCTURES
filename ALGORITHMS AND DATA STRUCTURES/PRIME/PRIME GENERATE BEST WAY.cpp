#include<bits/stdc++.h>
using namespace std;

const int maxi=1000005;
vector<int>v;
map<int,int>visit;

void seive()
{
    visit.clear();
    v.push_back(2);

    for(int i=3;i*i<=maxi;i+=2)
    {
        if(!visit[i])
        {
            for(int j=i*i;j<=maxi;j+=i)
                visit[j]=true;
        }
    }

    for(int i=3;i<=maxi;i+=2)
    {
        if(!visit[i])
            v.push_back(i);
    }
}

int main()
{
    seive();


    cout<<"ALL prime number between 1 to 10000000 ->> "<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    return 0;
}
