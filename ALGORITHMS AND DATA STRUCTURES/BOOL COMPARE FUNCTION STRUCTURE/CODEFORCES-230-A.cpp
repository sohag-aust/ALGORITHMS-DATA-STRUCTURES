#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxi=1005;

struct power{

    int a,b;
}st[maxi];

bool cmp(power a1,power b1)
{
    return a1.a<b1.a;
}

int main()
{
    int s,n;
    cin>>s>>n;
    int ara[n+2];

    for(int i=0; i<n; i++)
        cin>>st[i].a>>st[i].b;

    sort(st,st+n,cmp);

    int cnt=0;

    for(int i=0; i<n; i++)
    {
        int v1=st[i].a;
        int v2=st[i].b;

        if(v1<s)
        {
            s+=v2;
            cnt++;
        }
    }

    if(cnt==n) cout<<"YES";
    else cout<<"NO";
    cout<<endl;

    return 0;
}

