#include<bits/stdc++.h>
using namespace std;

const int maxi=30;

vector<int>edge[maxi];
vector<int>redge[maxi];
vector<int>ans[maxi];
vector<int>temp;
stack<int>st;
bool visit[maxi];

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        edge[i].clear();
        redge[i].clear();
        ans[i].clear();
        temp.clear();
    }
}

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
    bool blank=false;

    while(cin>>n>>e)
    {
        if(!n && !e) break;

        init(n);

        map<string,int>mp;
        map<int,string>Mp;
        map<string,bool>track;
        map<int,bool>slct;

        int c=1;

        static int kase=0;

        while(e--)
        {
            string s1,s2;
            cin>>s1>>s2;

            if(!track[s1])
            {
                mp[s1]=c;
                Mp[c]=s1;
                c++;
                track[s1]=true;
                slct[mp[s1]]=true;
            }

            if(!track[s2])
            {
                mp[s2]=c;
                Mp[c]=s2;
                c++;
                track[s2]=true;
                slct[mp[s2]]=true;
            }

            edge[mp[s1]].push_back(mp[s2]);
            redge[mp[s2]].push_back(mp[s1]);
        }

        if(blank)
            cout<<endl;
        blank=true;

        cout<<"Calling circles for data set "<<++kase<<":"<<endl;

        memset(visit,false,sizeof(visit));

        for(int i=1; i<=n; i++)
        {
            if(slct[i])
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

            for(int j=0; j<si; j++)
            {
                ans[cnt].push_back(temp[j]);
                flag=1;
            }

            if(flag) cnt++;
        }

        ///cout<<"Number of connected component: "<<cnt<<endl;

        for(int k=0; k<cnt; k++)
        {
            int si=ans[k].size();

            for(int j=0; j<si; j++)
            {
                if(j==si-1)
                    cout<<Mp[ans[k][j]];
                else
                    cout<<Mp[ans[k][j]]<<", ";
            }

            cout<<endl;
        }
    }

    return 0;
}

