#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,t;

    while(cin>>a>>b)
    {
        while(b!=0)
        {
            t = a;
            b = b%a;

            if(!b) break;

            a = b;
            b = t;
        }

        /**int gcd = __gcd(a,b);
        cout<<gcd<<endl;
        */

        /** Another Process :

            t = b;
            b = a%b;
            a = t;

        */

       /// cout<<a<<endl;
    }

    return 0;
}
