#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxi=1000005;

struct node
{
    ll a,b,diff;
} ara[maxi];

bool cmp(node lhs,node rhs)
{
    return lhs.diff>rhs.diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test;
    cin>>test;

    while(test--)
    {
        static ll cs=0;
        ll n,k;
        cin>>n>>k;

        for(int i=0; i<n; i++)
            cin>>ara[i].a;
        for(int i=0; i<n; i++)
            cin>>ara[i].b;

        for(int i=0; i<n; i++)
        {
            ll d = ara[i].a-ara[i].b;
            ara[i].diff=d;
        }

        sort(ara,ara+n,cmp);

        ll sum=0;

        for(int i=0; i<n; i++)
        {
            if(ara[i].diff>0)
            {
                if(k)
                {
                    k--;
                    continue;
                }

                else
                {
                    ll pro=ara[i].b-ara[i].a;
                    sum+=pro;
                }
            }

            else
            {
                ll pro=ara[i].b-ara[i].a;
                sum+=pro;
            }
        }

        if(sum<=0) cout<<"Case "<<++cs<<": No Profit";
        else cout<<"Case "<<++cs<<": "<<sum;
        cout<<endl;
    }

    return 0;
}
