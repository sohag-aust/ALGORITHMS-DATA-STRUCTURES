#include<bits/stdc++.h>
using namespace std ;
struct edges
{
    char x, y;
    int w ;
};
vector < edges > v, ans ;
char parent [100000 + 2] ;
bool cmp ( edges a, edges b )
{
    return a.w < b.w ;
}
char find( char u )
{
    while ( u != parent[u] ) u = parent[u] ;
    return u ;
}
void make_union ( char u, char v )
{
    parent[u] = v ;
}
int main ()
{

    int n, e ;
    cout << "Enter number of vertices and edges :: " ;
    cin >> n >> e ;
    cin.ignore();
    for ( int i = 1 ; i <= n ; i++ )
    {
        parent[(char)i+64] = (char)i+64 ;
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
        char uu = find ( v[i].x ) ;
        char vv = find ( v[i].y ) ;

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
    cout << sum << endl ;

    return 0;
}
