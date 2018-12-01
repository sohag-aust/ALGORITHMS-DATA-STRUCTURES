#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout<<"Enter a number: ";

    while(cin>>n)
    {
        vector<int>v;

        int temp = n;

        while(temp!=0)
        {
            v.push_back(temp%2);
            temp/=2;
        }

        reverse(v.begin(),v.end());

        int t = v[0];
        int sz = v.size();

        for(int i=1; i<sz; i++)
        {
            v[i-1] = v[i];
        }

        v[sz-1] = t;

        reverse(v.begin(),v.end());

        int sum=0;

        for(int i=0; i<v.size(); i++)
        {
            double val = pow((double)2,(double)i);
            int val1 = (int)val * v[i];

            sum+=val1;
        }

        cout<<"\n"<<sum<<"'th man escaped.."<<endl;

        cout<<"\nEnter a number: ";
    }

    return 0;
}
