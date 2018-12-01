#include <bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    string s,str;
    int i,lenth,t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        lenth=s.size();
        str=s;
        s+=s;
        for(i=0; i<lenth; i++)
        {
            str=min(str,s.substr(i,lenth));
        }
        cout<<str<<endl;
    }

    return 0;
}

