#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int ara[n+5];

    for(int i=0; i<n; i++) cin>>ara[i];

    int sum,maxi;
    int start_index,end_index;

    sum = 0;
    int w;

    cin>>w;

    start_index = 0;
    end_index = w-1;

    for(int i=0; i<w; i++) sum+=ara[i];

    maxi = sum;

    for(int i=w ; i<n; i++)
    {
        sum = sum + (ara[i] - ara[i-w]);

        if(sum > maxi)
        {
            maxi = sum;
            start_index = (i-w)+1;
            end_index = i;
        }
    }

    cout<<"\nMaximum Sum: "<<maxi<<endl;

    cout<<"\nMaximum Sub Array ->> "<<endl;

    for(int i=start_index ; i<=end_index ; i++)
        cout<<ara[i]<<" ";
    cout<<endl;

    return 0;
}
