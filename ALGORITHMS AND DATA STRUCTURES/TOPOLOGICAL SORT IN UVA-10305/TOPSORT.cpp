/// STRAIGHT FORWARD TOPSORT...

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x,y;

    while(cin>>n>>m)
    {
        if(!n && !m) break;

        vector<int>v[n+2];
        map<int,int>indegree;

        while(m--)
        {
            cin>>x>>y;

            v[x].push_back(y);

            indegree[y]++;
        }

        queue<int>q;

        for(int i=1;i<=n;i++)
        {
            if(!indegree[i])
                q.push(i);
        }

        vector<int>sortlist;

        while(!q.empty())
        {
            int top=q.front();
            q.pop();

            sortlist.push_back(top);

            int size=v[top].size();

            for(int i=0;i<size;i++)
            {
                indegree[v[top][i]]--;

                if(!indegree[v[top][i]])
                    q.push(v[top][i]);
            }
        }

        for(int i=0;i<sortlist.size();i++)
            cout<<sortlist[i]<<" ";
        cout<<endl;
    }

    return 0;
}
