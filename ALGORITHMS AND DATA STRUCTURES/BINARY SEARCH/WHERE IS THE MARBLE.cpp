#include<bits/stdc++.h>
using namespace std;

void binary(vector<int>&v, int n, int s)
{
    int f,l,m;

    f=0;
    l=n-1;
    m=(f+l)/2;

    while(f<=l)
    {
        if(v[m]==s)
        {
            while(v[m]==s && m>=0)
            {
                m--;
            }

            cout<<s<<" found at "<<m+2<<endl;

            break;
        }

        else if(v[m]<s)
            f=m+1;

        else
            l=m-1;

        m=(f+l)/2;
    }

    if(f>l)
        cout<<s<<" not found"<<endl;
}

int main()
{
    int n,s1,s,cs=0,val;
    vector<int>v1;
    vector<int>v2;

    while(cin>>n>>s1)
    {
        if(!n && !s1)
            break;

        for(int i=0; i<n; i++)
        {
            cin>>val;
            v1.push_back(val);
        }

        sort(v1.begin(),v1.end());

        for(int i=0; i<s1; i++)
        {
            cin>>val;
            v2.push_back(val);
        }

        cout<<"CASE# "<<++cs<<":"<<endl;
        for(int i=0; i<v2.size(); i++)
        {
            s=v2[i];
            binary(v1,n,s);
        }

        v1.clear();
        v2.clear();
    }

    return 0;
}
