#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 1e4 + 9, INF = 1e9;
int st, en;

vector<pair <int, int> > edges[MAX+9];
int dis[MAX+9];

void setUp(int n)
{
    for(int i=0; i<=n; i++)
    {
        edges[i].clear();
        dis[i] = INF;
    }
}

void Dijkstra(int i)
{
    priority_queue<ii, vector<ii>, greater<ii> >pq;
    /// eitar maddhome jar cost choto sei edge nie kaj krbe..

    dis[i] = 0;
    pq.push(make_pair(0, i));

    while(!pq.empty())
    {
        int t = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        int si = edges[u].size();

        for(int j=0; j<si; j++)
        {
            int v = edges[u][j].first;
            int c = edges[u][j].second;

            if(dis[v]>dis[u]+c)
            {
                dis[v] = dis[u] + c;

                pq.push(make_pair( dis[v],v )); /// eitar maddhome jar cost kom take dhore agabe..
                ///pq.push(make_pair( v,-dis[v] )); /// eitar maddhome jei node ta choto oi node dhore agabe..
            }
        }
    }
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
            //edges[in2].push_back(make_pair(in1, in3));
        }

        cout<<"\nEnter starting node: ";
        cin >> st;
        cout<<"Enter ending node: ";
        cin >> en;

        Dijkstra(st);

        if(dis[en]==INF)cout << "NO" << endl;
        else cout <<"\n\nTotal cost (Minimum cost): "<< dis[en] << endl;
    }

    return 0;
}

/**
1
5
6

1 4 1
1 2 2
2 5 5
2 3 4
3 5 1
4 3 3

1
5

output: 5
*/


/**
GEEKS FOR GEEKS INPUT:
1
9 14
0 1 4
0 7 8
1 2 8
1 7 11
7 8  7
7 6 1
2 8 2
8 6 6
2 5 4
6 5 2
2 3 7
3 4 9
3 5 14
5 4 10
0
4

OUTPUT:
21

*/
