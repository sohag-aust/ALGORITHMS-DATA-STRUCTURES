#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

void primeFactors(int n)
{
    while(n%2==0)
    {
        ans.push_back(2);
        n=n/2;
    }

    for(int i = 3; i <= sqrt(n); i = i+2)
    {
        while(n%i==0)
        {
            ans.push_back(i);
            n=n/i;
            cout<<"n: "<<n<<endl;
        }
    }

    if(n>2)
        ans.push_back(n);
}

int main()
{
    int n;
    while(cin>>n)
    {
        ans.clear();

        if(n==0) break;
        if(n<0)
        {
            n=(-1)*n;
            cout<<"-"<<n<<" = -1 x ";
        }

        else
            cout<<n<<" = ";

        primeFactors(n);

        for(int i=0; i<ans.size(); i++)
        {
            if(i==ans.size()-1)
                cout<<ans[i]<<endl;
            else
                cout<<ans[i]<<" x ";
        }
    }

    return 0;
}

