
#include<bits/stdc++.h>
using namespace std;

int parent[100010];
set<int>st;
map<int,bool>visit;
int cnt=0;
vector<int>vec;

void make_set(int n)
{
    for(int i=1; i<=n; i++)
        parent[i]=i;
}

int find_set(int r)
{
    if(parent[r]==r) return r;
    return parent[r]=find_set(parent[r]);
}

void set_union(int u,int v)
{
    if(u!=v)
        parent[v]=u;
}

int main()
{
    int test;
    int node,edge;
    cin>>test;

    while(test--)
    {
        cin>>node>>edge;

        make_set(node);
        set<int>st1;
        st.clear();

        while(edge--)
        {
            int x,y;
            cin>>x>>y;
            st1.insert(x);
            st1.insert(y);
            int u=find_set(x);
            int v=find_set(y);

            set_union(u,v);
        }

        int tot=node-st1.size();
        int si=st.size();

        for(int i=1;i<=node;i++)
        {
            cout<<"parent of "<<i<<" :-> "<<find_set(parent[i])<<endl;
        }
    }

    return 0;
}
