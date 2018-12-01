#include<bits/stdc++.h>
using namespace std ;

struct edges
{
    int x, y, w ;
};
vector < edges > v, ans ;

int parent [100000 + 2] ;

bool cmp ( edges a, edges b )
{
    return a.w < b.w ;
}

int find( int u )
{
    while ( u != parent[u] ) u = parent[u] ;
    return u ;
}

void make_union ( int u, int v )
{
    if(u>v)
        parent[u] = v ;
    else
        parent[v] = u ;
}

int main ()
{

    int n, e ;
    cout << "Enter number of vertices and edges :: " ;
    cin >> n >> e ;

    for ( int i = 1 ; i <= n ; i++ )
    {
        parent[i] = i ;
    }

    cout << "Enter the edges :: " ;

    while ( e-- )
    {
        edges curr ;
        cin >> curr.x >> curr.y >> curr.w ;
        v.push_back ( curr ) ;
    }

    sort ( v.begin (), v.end (), cmp ) ;

    for ( int i = 0 ; i < v.size () ; i++ )
    {
        int uu = find ( v[i].x ) ;
        int vv = find ( v[i].y ) ;

        if ( uu != vv )
        {
            make_union ( uu, vv ) ;
            ans.push_back ( v[i] ) ;
        }
    }

    int sum = 0 ;

    cout << "The edges of minimum spanning tree :: " << endl ;

    for ( int i = 0 ; i < ans.size () ; i++ )
    {
        cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].w << endl ;
        sum += ans[i].w ;
    }

    cout <<"\n\nMinimum cost: "<< sum << endl ;

    return 0;
}

/**
sample input:
7 11

0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11

sample output:
39

*/
