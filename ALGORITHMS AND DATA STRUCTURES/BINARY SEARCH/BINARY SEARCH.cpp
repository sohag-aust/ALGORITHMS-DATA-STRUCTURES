#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    cin>>n;
    int ara[n+1];

    for(int i=0; i<n; i++)
        cin>>ara[i];

    cin>>s;

    sort(ara,ara+n);
    int f,l,m;

    f=0;
    l=n-1;
    m=(f+l)/2;

    while(f<=l)
    {
        if(ara[m]==s)
        {
            cout<<"Value found at "<<m+1<<"'th index.."<<endl;
            break;
        }

        else if(ara[m]>s)
            l=m-1;

        else if(ara[m]<s)
            f=m+1;

        m=(f+l)/2;
    }

    if(f>l)
        cout<<"Value not found.."<<endl;

    return 0;
}
