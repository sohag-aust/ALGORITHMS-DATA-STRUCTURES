#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ara[50];

void fibo()
{
    ara[0] = 0;
    ara[1] = 1;

    for(int i=2;i<=43;i++)
    {
        ara[i] = ara[i-1]+ara[i-2];
    }
}

int main()
{
    fibo();

    int test;
    cin>>test;

    while(test--)
    {
        ll n,sum = 0;

        cin>>n;
        vector<int>v;

        for(int i=40;i>=2;i--)
        {
            ll val = ara[i];

            if(val>n) continue;

            else
            {
                sum+=ara[i];

                if(sum<=n)
                {
                    v.push_back(1);
                }

                else if(sum>n)
                {
                    v.push_back(0);
                    sum-=ara[i];
                }
            }
        }

        int flag = 0;

        cout<<n<<" = ";

        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0 && flag)
                cout<<v[i];

            else if(v[i]==1)
            {
                cout<<v[i];
                flag = 1;
            }
        }

        cout<<" (fib)"<<endl;
    }

    return 0;
}
