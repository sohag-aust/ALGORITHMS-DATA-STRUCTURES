/// kon number er sob ceye besi divisor ache seta ber kora...

#include<bits/stdc++.h>
using namespace std;

const int MAX=40;
vector<int>d(MAX);
vector<int>best(MAX);

void divisor()
{
    for(int i=2; i<MAX; i++)
        for(int j=i; j<MAX; j+=i)
            d[j]++;

    best[1]=1;

    for(int i=2; i<MAX; i++)
    {
        if(d[best[i-1]]>d[i])
        {
            best[i]=best[i-1];
        }

        else
        {
            best[i]=i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    divisor();

    int test;
    cin>>test;

    while(test--)
    {
        int n;
        cin>>n;
        cout<<best[n]<<endl;
    }

    return 0;
}
