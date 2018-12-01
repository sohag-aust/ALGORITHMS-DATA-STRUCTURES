/// LCM = (multiplication of 2 number) / gcd;

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,t;

    while(cin>>a>>b)
    {
        int multi = a*b;

        while(b)
        {
            t = a;
            b = b%a;

            if(!b) break;

            a = b;
            b = t;
        }

        int gcd = a;

        int lcm = multi / gcd;

        cout<<lcm<<endl;
    }

    return 0;
}
