#include<bits/stdc++.h>
using namespace std;

char parent[100];

struct edges
{
    char from;
    char to;
} dset;

vector<edges>v;

void makeset(int n)
{
    for(int i=1; i<=n; i++)
        parent[(char)(i+64)]=(char)(i+64);
}

char findset(char r)
{
    if(parent[r]==r) return r;

    else
    {
        parent[r]=findset(parent[r]);
        return parent[r];
    }
}

void setunion(char uu,char vv)
{
    char u1=findset(uu);
    char v1=findset(vv);

    if(u1==v1) cout<<"They are already friend..."<<endl;
    else parent[u1]=v1;
}

int main()
{
    int node,edge;

    cin>>node>>edge;

    makeset(node);

    while(edge--)
    {
        char x,y;

        cin>>x>>y;

        dset.from=x;
        dset.to=y;

        v.push_back(dset);
    }

    for(int i=0; i<v.size(); i++)
    {
        char uu=v[i].from;
        char vv=v[i].to;

        setunion(uu,vv);
    }

    for(int i=1; i<=node; i++)
    {
        cout<<"Parent of "<<(char)(i+64)<<" is "<<parent[(char)(i+64)]<<endl;
    }

    cout<<endl;

    for(int i=1; i<=node; i++)
    {
        cout<<"Find set of "<<(char)(i+64)<<" is "<<findset((char)i+64)<<endl;
    }

    cout<<endl;

    for(int i=1; i<=node; i++)
    {
        cout<<"Parent of "<<(char)(i+64)<<" is "<<parent[(char)(i+64)]<<endl;
    }

    cout<<endl;

    return 0;
}
/**
input:

9 8
A B
C B
D E
E B
G F
G C
I H
I D

*/
