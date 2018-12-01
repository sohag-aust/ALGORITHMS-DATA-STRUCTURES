#include<bits/stdc++.h>
using namespace std;

map<int,bool>mp;
vector<int>edge[10];
vector<int>redge[10];
vector<int>ans[10];
vector<int>temp;
stack<int>st;
bool visit[10];

void dfs(int i)
{
    if(visit[i]) return ;

    visit[i]=true;

    int si=edge[i].size();
    for(int j=0; j<si; j++)
    {
        int val=edge[i][j];
        if(!visit[val])
            dfs(val);
    }

    st.push(i);
}

void dfs_rev(int i)
{
    if(visit[i]) return ;

    temp.push_back(i);
    visit[i]=true;

    int si=redge[i].size();

    for(int j=0; j<si; j++)
    {
        int val=redge[i][j];
        if(!visit[val])
            dfs_rev(val);
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    while(e--)
    {
        int x,y;
        cin>>x>>y;
        mp[x]=mp[y]=true;
        edge[x].push_back(y);
        redge[y].push_back(x);
    }

    memset(visit,false,sizeof(visit));

    for(int i=1; i<=n; i++)
    {
        if(mp[i])
        {
            if(!visit[i])
                dfs(i);
        }
    }

    memset(visit,false,sizeof(visit));
    int cnt=0,flag;

    while(!st.empty())
    {
        flag=0;
        int top=st.top();
        st.pop();

        temp.clear();
        dfs_rev(top);

        sort(temp.begin(),temp.end());

        int si=temp.size();

        for(int k=0; k<si; k++)
        {
            ans[cnt].push_back(temp[k]);
            flag=1;
        }

        if(flag)
            cnt++;
    }

    cout<<"\nTotal Strongly Connected Component: "<<cnt<<endl;

    cout<<"\nElements of each component are ->> "<<endl<<endl;

    for(int i=0; i<cnt; i++)
    {
        cout<<"Component # "<<i+1<<" ->> ";
        int si=ans[i].size();
        for(int j=0; j<si; j++)
        {
            if(j==si-1)
                cout<<ans[i][j];
            else
                cout<<ans[i][j]<<",";

        }
        cout<<endl;
    }

    return 0;
}
