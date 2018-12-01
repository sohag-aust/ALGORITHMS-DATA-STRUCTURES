#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int cnt = 0;

        for(int i=1;i*i<=n;i++)
        {
            if(i*i == n) cnt++;
            else if(n%i == 0) cnt+=2;
        }

        cout<<cnt<<endl;
    }

    return 0;
}
