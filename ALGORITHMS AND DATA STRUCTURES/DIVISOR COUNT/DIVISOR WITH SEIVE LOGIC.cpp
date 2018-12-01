#include<bits/stdc++.h>
using namespace std;

const int maxi=100005;

int sum[maxi],num[maxi];

void Divisor()
{
    int i,j,k,s;

    memset(num,0,sizeof(num));
    memset(sum,0,sizeof(sum));

    for(i=1; i<=maxi; i++)
    {
        for(j=i; j<=maxi; j+=i)
        {
            num[j]+=1; /// number of divisors for each number between 1 to maxi.
            sum[j]+=i; /// sum of divisors for each number between 1 to maxi.
        }
    }
}

int main()
{
    Divisor();

    long int a,b,k,cas,i,j,l,n,s;

    scanf("%ld",&cas);
    for(l=1; l<=cas; l++)
    {
        scanf("%ld%ld%ld",&a,&b,&k);
        n = 0;
        s = 0;

        for(i=a; i<=b; i++)
        {
            if(i%k==0)
            {
                n+=num[i];
                s+=sum[i];
            }
        }

        printf("%ld %ld\n",n,s);
    }

    return 0;
}
