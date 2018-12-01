#include<bits/stdc++.h>
using namespace std;

int visit[100],level[100];
vector<int>traverse[100];
vector<int>v[100];

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visit[source]=1;
    level[source]=0;

    while(!q.empty())
    {
        int frnt=q.front();

        q.pop();

        int sz=v[frnt].size();

        for(int i=0; i<sz; i++)
        {
            int val=v[frnt][i];

            traverse[frnt].push_back(val);

            if(!visit[val])
            {
                visit[val]=1;
                level[val]=level[frnt]+1;
                q.push(val);
            }
        }
    }
}

int main()
{
    vector<int>vec[100];
    map<int,int>mp;
    int edge,a,b;

    cin>>edge;

    while(edge--)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout<<"Enter the source: ";
    int source;
    cin>>source;

    bfs(source);

    cout<<"\nTraverse from vertex to vertex->> "<<endl<<endl;

    for(int i=1; i<=20; i++)
    {
        int len=traverse[i].size();

        cout<<"Traverse from "<<i<<" to -> ";

        for(int j=0; j<len; j++)
        {
            cout<<traverse[i][j]<<" ";
        }

        cout<<endl;
    }

    int t=20;

    cout<<endl;

    while(t--)
    {
        cout<<"Enter the vertex number: ";
        int l;
        cin>>l;

        vec[level[l]].push_back(l);
        mp[l]=level[l];
    }

    cout<<endl<<endl;

    for(int i=0; i<10; i++)
    {
        int len=vec[i].size();

        cout<<"vertices in level: "<<i<<" are -> ";

        if(len)
        {
            for(int j=0; j<len; j++)
            {
                cout<<vec[i][j]<<" ";
            }
        }

        else
            cout<<"empty.";

        cout<<endl;
    }

    cout<<"\nEnter vertex to see its' level: ";
    int vert;
    cin>>vert;
    cout<<"\nVertex "<<vert<<" is in Level: "<<mp[vert]<<endl;

    return 0;
}
