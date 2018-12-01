#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val,point;

    node(int _val,int _point)
    {
        val = _val;
        point = _point;
    }
};

bool operator <(const node & a, const node & b)
{
    if(a.val == b.val) return a.point > b.point;
    return a.val > b.val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    while(cin>>n,n)
    {
        priority_queue<node>pq;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int val;
            cin>>val;
            pq.push(node(val,1));
        }

        int sum,cnt = 0;

        while(pq.size() > 1 && cnt <= n)
        {
            int first = pq.top().val;
            pq.pop();
            int second = pq.top().val;
            pq.pop();

            sum = first + second;
            ans += sum;

            pq.push(node(sum,2));

            if(pq.top().point == 1)
                cnt++;
        }

        cout<<ans<<endl;
    }

    return 0;
}
