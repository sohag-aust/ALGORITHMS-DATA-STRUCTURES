#include<bits/stdc++.h>
using namespace std;

int parent[1234];
int level[1234];
vector<int> edges[1234];
int start_node;
bool visit[100];
int last;

void print(int i)
{
    ///cout<<"I is: "<<i<<endl;
    if(parent[i]!=i)
    {
        /// cout<<"parent: "<<parent[i]<<endl; /// store in buffer..
        /// 1st buffer e store hobe 5 .. 2nd buffer e store hobe 4 and then buffer e store hobe 1...
        print(parent[i]);
    }

    /// cout<<"I here: "<<i<<endl;
    ///cout<<"parent[i] here: "<<parent[i]<<endl;

    if(!visit[parent[i]])
    {
        if(parent[i]==last)
            visit[last]=true;

        cout << parent[i] << endl;
        visit[parent[i]]=true;
    }

    /// cout<<"BYE SHOHAG.."<<endl;

    /// eikhane 1 bar bye shohag hoe gele then buffer theke value nie nie print hobe...
    /// this is the recurrence...
}

void bfs(int i)
{
    ///last = 1;
    queue<int>current;
    current.push(i);
    level[i] = 1;

    while(!current.empty())
    {
        i = current.front();
        current.pop();

        int si = edges[i].size();

        for(int j=0; j<si; j++)
        {
            int x=edges[i][j];

            if(level[x]==0)
            {
                level[x] = level[i] + 1;
                current.push(x);
                parent[x] = i;
                ///last = x;
            }
        }
    }

    print(last);
}


int main(void)
{
    for(int i=0; i<1234; i++)
    {
        parent[i] = i;
        level[i] = 0;
    }

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int in1, in2;
        cin >> in1 >> in2;

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    cout<<"Enter the starting node: ";
    cin>>start_node;
    cout<<"Enter the ending node: ";
    cin>>last;

    bfs(start_node);

    if(!visit[last]) cout<<last<<endl;

    return 0;
}



/**
correct
9 17
1 2
1 3
1 4
3 2
4 3
2 5
5 3
6 3
7 3
4 7
6 5
7 6
8 5
6 8
9 6
8 9
9 7

for directed: 1->4->7->6->8->9
for undirected: 1->3->6->9
*/
