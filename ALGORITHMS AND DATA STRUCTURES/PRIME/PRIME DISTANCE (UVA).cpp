#include<bits/stdc++.h>
using namespace std ;

#define maximum 1000000

typedef long long ll ;

ll visit[maximum+2] ;
ll prime[maximum+2] ;
ll k;

void seive()
{
    visit[0] = visit[1] = 1;
    visit[2] = 0;

    k = 0;

    for(int l=2 ; l<=maximum ; l++)
    {
        if(!visit[l])
        {
            prime[k++] = l ;

            for(int j =l*2 ; j<=maximum ; j+=l)
            {
                visit[j] =1 ;
            }
        }
    }
}

bool isPrime(ll n)
{
    if(n <= maximum)
    {
        if(visit[n]==0)
            return true ;

        else
            return false ;
    }
    else
    {
        for(ll j=0 ; j<k && prime[j]<=sqrt(n) ; j++)
        {
            if(n%prime[j]==0)
                return false ;
        }

        return true ;
    }
}


int main()
{
    ll n,m;

    seive();

    while(cin>>n>>m)
    {
        ll mini = 1e9;
        ll maxi = 0 ;
        ll prev = -1;

        pair<ll,ll>close,distant;

        for(ll i = n ; i<=m ; i++)
        {
            if(isPrime(i))
            {
                if(prev != -1)
                {
                    ll diff = i-prev;

                    if(diff < mini)
                    {
                        close = {prev,i};
                        mini = diff;
                    }

                    if(diff > maxi)
                    {
                        distant = {prev,i};
                        maxi = diff;
                    }
                }

                prev = i;
            }
        }

        if(mini == 1e9)
            cout<<"There are no adjacent primes.";

        else
            printf("%lld,%lld are closest, %lld,%lld are most distant.",close.first, close.second, distant.first, distant.second);

        cout<<endl;
    }

    return 0;
}
