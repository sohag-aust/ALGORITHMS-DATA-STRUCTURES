#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 1e4 + 9, INF = 1e9;
int st, en;
vector<int>vec;
bool visit[100];

vector<pair <int, int> > edges[MAX+9];
int dis[MAX+9];
int parent[1000];

void setUp(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i]=i;
        edges[i].clear();
        dis[i] = INF;
    }
}

void print(int i)
{
    if(parent[i]!=i)
    {
        print(parent[i]);
    }

    if(!visit[parent[i]])
    {
        if(parent[i]==en)
            visit[en]=true;

        cout<<parent[i]<<"  ";
        visit[parent[i]]=true;
    }
}

void Dijkstra(int i)
{
    priority_queue<pair < int, int > > pq;

    dis[i] = 0;

    pq.push(make_pair(i, 0));

    while(!pq.empty())
    {
        int u = pq.top().first;
        int t = pq.top().second;

        pq.pop();

        int si = edges[u].size();

        for(int j=0; j<si; j++)
        {
            int v = edges[u][j].first;
            int c = edges[u][j].second;

            if(dis[v] > dis[u]+c)
            {
                dis[v] = dis[u] + c;
                pq.push(make_pair( v,-dis[v]));
                parent[v]=u;
            }
        }
    }

    cout<<"\nThe Shortest Path is->>"<<endl;

    print(en);
}

int main(void)
{
    int t;
    cout<<"Enter the number of test case: ";
    cin >> t;
    while(t--)
    {
        int n, m;
        cout<<"\nEnter the number of node: ";
        cin >> n;
        cout<<"Enter the number of edge: ";
        cin >> m;
        setUp(n);

        cout<<"\nEnter nodes and cost between nodes ->>\n";

        while(m--)
        {
            int in1, in2, in3;
            cin >> in1 >> in2 >> in3;

            edges[in1].push_back(make_pair(in2, in3));
        }

        cout<<"\nEnter starting node: ";
        cin >> st;
        cout<<"Enter ending node: ";
        cin >> en;

        Dijkstra(st);
        if(!visit[en]) cout<<en<<endl;

        if(dis[en]==INF)cout << "NO" << endl;
        else cout <<"\nTotal cost (Minimum cost): "<< dis[en] << endl;
    }

    return 0;
}

