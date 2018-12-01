#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    while(cin>>n && n)
    {
        multiset<int>mst;
        ll sum = 0;

        while(n--)
        {
            int k;
            cin>>k;

            while(k--)
            {
                int val;
                cin>>val;
                mst.insert(val);
            }

            auto it_fast = mst.begin();  /// find the first element
            auto it_last = mst.rbegin(); /// find the last element

            sum += *it_last - *it_fast;

            mst.erase(mst.begin());      /// erase the first element
            mst.erase(prev(mst.end()));  /// erase the last element
        }

        cout<<sum<<endl;
    }

    return 0;
}

