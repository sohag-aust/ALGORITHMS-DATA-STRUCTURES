#include<bits/stdc++.h>
using namespace std;

#define maxi 1010

vector<int>v[maxi];
vector<int>vc;

int mp[maxi]= {0};

void init()
{
    for(int i=0; i<maxi; i++) v[i].clear();
}

bool prime(int n)
{
    if(n==2 || n==1) return true;
    if(n%2==0) return false;
    if(!mp[n]) return true;
    return false;
}

void pre()
{
    for(int i=3; i*i<=maxi; i+=2)
    {
        if(!mp[i])
        {
            for( int j=(i*i) ; j<= maxi ; j+=(i+i) )
            {
                mp[j] = 1;
            }
        }
    }
}

int main()
{
    pre();

    int n,c;

    while(cin>>n>>c)
    {
        init();

        for(int i=1; i<=n; i++)
        {
            bool res = prime(i);

            if(res) v[n].push_back(i);
        }

        int sz = v[n].size();

        cout<<n<<" "<<c<<": ";

        int limit=0;

        if(sz%2==0) limit = 2*c;
        else limit = (2*c)-1;

        if(limit >= sz)
        {
            for(int i=0; i<sz; i++)
            {
                if(i<sz-1) cout<<v[n][i]<<" ";
                else cout<<v[n][i];
            }
        }

        else
        {
            int val = sz-limit;

            val/=2;

            limit = val+limit;

            for(int i=val; i<limit; i++)
            {
                if(i<limit-1) cout<<v[n][i]<<" ";
                else cout<<v[n][i];
            }
        }

        cout<<endl<<endl;
    }

    return 0;
}
