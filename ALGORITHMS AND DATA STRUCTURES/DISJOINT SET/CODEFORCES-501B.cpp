#include<bits/stdc++.h>
using namespace std;

map<string,string>parent,ans;
set<string>st;
string child,temp;
int cnt=0;

struct node
{
    string old_id;
    string new_id;
} edge;

string findset(string s)
{
    if(parent[s]==s)
        return s;

    if(cnt==0)
    {
        child=s;
        cnt++;
    }

    parent[s]=findset(parent[s]);

    cnt=0;
    temp=parent[s];

    ans[temp]=child;

    return parent[s];
}

void setunion(string s1,string s2)
{
    string u=findset(s1);
    string v=findset(s2);

    st.insert(u);
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();

    vector<node>edges;

    while(n--)
    {
        cin>>edge.old_id>>edge.new_id;

        parent[edge.old_id]=edge.old_id;
        parent[edge.new_id]=edge.new_id;

        edges.push_back(edge);
    }

    for(int i=0; i<edges.size(); i++)
    {
        parent[edges[i].new_id]=edges[i].old_id;

        string s1=edges[i].old_id;
        string s2=edges[i].new_id;

        setunion(s1,s2);
    }

    set<string>::iterator it;

    it=st.begin();

    cout<<st.size()<<endl;

    while(it!=st.end())
    {
        cout<<*it<<" "<<ans[*it]<<endl;
        it++;
    }

    return 0;
}

