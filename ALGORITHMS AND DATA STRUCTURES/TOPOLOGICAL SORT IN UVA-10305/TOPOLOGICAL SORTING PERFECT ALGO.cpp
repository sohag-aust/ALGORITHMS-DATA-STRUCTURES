#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node,edge;

    while(cin>>node>>edge)
    {
        if(!node) break;

        vector<int>v[110];
        map<int,int>indeg;
        vector<int>ans;

        while(edge--)
        {
            int a,b;

            cin>>a>>b;

            v[a].push_back(b);

            indeg[b]++;
        }

        while(true)
        {
            for(int i=1;i<=node;i++)
            {
                ///cout<<"i: "<<i<<endl;
                ///cout<<"degree: "<<indeg[i]<<endl;

                if(!indeg[i])
                {
                    ans.push_back(i);
                    indeg[i]--;

                    int sz = v[i].size();

                    for(int j=0;j<sz;j++)
                        indeg[v[i][j]]--;

                    break;
                }
            }

            if(ans.size() == node) break;
        }

        for(int i=0;i<ans.size();i++)
        {
            if(i<ans.size()-1) cout<<ans[i]<<" ";
            else cout<<ans[i];
        }

        cout<<endl;
    }

    return 0;
}
/**
5 4
1 2
2 3
1 3
1 5
0 0
*/
