#include<bits/stdc++.h>
using namespace std;

#define maxi 100000
int phi[maxi+5];

void pre_phi()
{
    for(int i=1; i<=maxi; i+=2) phi[i] = i;
    for(int i=2; i<=maxi; i+=2) phi[i] = i/2;

    for(int i=3; i<=maxi; i+=2)
    {
        if(phi[i] == i)
        {
            phi[i]--;

            for(int j=i+i; j<=maxi; j+=i)
            {
                phi[j] = phi[j] - (phi[j]/i);
            }
        }
    }
}

int main()
{
    pre_phi();

    int query;
    cout<<"Enter a number of query: ";
    cin>>query;

    while(query--)
    {
        int n;
        cout<<"\nEnter a number: ";
        cin>>n;

        cout<<"PHI of "<<n<<" is: "<<phi[n]<<endl;
    }

    return 0;
}
