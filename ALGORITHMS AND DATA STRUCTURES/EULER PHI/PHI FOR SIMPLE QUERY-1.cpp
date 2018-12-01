#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int cnt=0;
    vector<int>ans;

    for(int i=1;i<=n;i++)
    {
        int gcd = __gcd(i,n);

        if(gcd == 1)
        {
            ans.push_back(i);
            cnt++;
        }
    }

    cout<<"\nTotal number of relative prime of "<<n<<" is: "<<cnt<<endl;
    cout<<"\nThe relative prime numbers of "<<n<<" are -> ";

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}
