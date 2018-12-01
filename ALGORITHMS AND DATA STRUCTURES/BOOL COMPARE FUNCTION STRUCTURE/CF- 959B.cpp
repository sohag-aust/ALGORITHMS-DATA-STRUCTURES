#include<bits/stdc++.h>
using namespace std;

#define maxi 100010
typedef long long ll;

vector<string>vs;
map<string,ll>mp1;
map<ll,ll>mp2;

struct node
{
    string name;
    ll cost;

    node(string _name,ll _cost)
    {
        name = _name;
        cost = _cost;
    }
};

vector<node>vec,v[maxi];

bool cmp(node a,node b)
{
    return a.cost<b.cost;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,k,m;

    cin>>n>>k>>m;

    for(int i=0;i<n;i++)
    {
        string ss;
        cin>>ss;
        vs.push_back(ss);
    }

    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;

        vec.push_back(node(vs[i],c));
        mp1[vs[i]] = i;
    }

    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;

        for(int j=0;j<x;j++)
        {
            int in;
            cin>>in;

            in--;

            v[i].push_back(vec[in]);
            mp2[in] = i;
        }

        sort(v[i].begin(),v[i].end(),cmp);
    }

    ll sum = 0;

    for(int i=0;i<m;i++)
    {
        string ss;
        cin>>ss;

        int temp = mp2[mp1[ss]];

        sum += v[temp][0].cost;
    }

    cout<<sum<<endl;

    return 0;
}


