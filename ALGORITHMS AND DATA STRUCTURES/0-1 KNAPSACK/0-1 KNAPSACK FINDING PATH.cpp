#include <bits/stdc++.h>

using namespace std;

#define PP pair<int,int>
int n,target;
int cost[102], weight[102];
int CAP;

pair<int,int> Knap(int i,int w)
{
    if(i==n+1) return make_pair(0,w);
    pair<int,int> profit1, profit2;

    if(w+weight[i]<=CAP)
    {
        pair<int,int> tmp = Knap(i+1, w + weight[i]);
        profit1 = make_pair(tmp.first+cost[i], tmp.second);
    }
    else
        profit1 = make_pair(0,0);

    profit2=Knap(i+1,w);
    return max(profit1, profit2);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>CAP;

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&weight[i],&cost[i]);
        }
        pair<int,int>P;
        P=Knap(1,0);

        cout<<P.first<<" "<<P.second<<endl;
    }
    return 0;
}
