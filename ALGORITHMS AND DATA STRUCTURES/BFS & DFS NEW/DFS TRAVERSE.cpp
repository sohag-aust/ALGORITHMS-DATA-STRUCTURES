#include<bits/stdc++.h>
using namespace std;

vector<int>v[100] ;
int vis[1000] ;
int last;

void dfs(int s)
{
    if(s==last)
    {
        cout<<last<<endl;
        return ;
    }

    if(!vis[s])
    {
        cout<<s<<endl;
        vis[s]=1;
    }

    int sz = v[s].size();

    for(int i = 0 ; i<sz ; i++ )
    {
        int val = v[s][i];

        if(!vis[val])
        {
            cout<<"val: "<<val<<endl;
            dfs(val);
        }
    }
}

int main()
{
    int edge,i,j;

    cin>>edge;

    while(edge--)
    {
        cin>>i>>j;
        v[i].push_back(j);
        v[j].push_back(i) ;
    }

    int start;
    cout<<"start node: ";
    cin>>start;

    cout<<"Reach node: ";
    cin>>last;

    cout<<endl;

    dfs(start) ;

    return 0;
}

/**
input algorithm khatai ache...

10
1 2
1 3
2 4
2 5
4 8
4 9
3 6
3 7
6 10
10 11

1
11

output:
1
2
4
8
9
5
3
6
10
11
7
*/

