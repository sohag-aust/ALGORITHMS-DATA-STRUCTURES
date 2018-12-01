#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

struct degree
{
    int inDegree;
    int outDegree;
}
degrees[20];

#define MAX 100000

vector < int > edges[MAX];

int totalAdjacents[20];

int main()
{
    int N, E, i;

    scanf( "%d %d", &N, &E );

    for( i = 1; i <= E; i++ )
    {
        int x, y;

        scanf( "%d %d", &x, &y );

        edges[x].push_back( y );
    }

    for( int i = 1; i <= N; i++ )
    {
        degrees[i].inDegree = 0;
        degrees[i].outDegree = 0;
    }

    for( int i = 1; i <= N; i++ )
    {
        printf( "Node %d is connected with =>", i );

        int adj_nodes = edges[i].size();

        for( int j = 0; j < adj_nodes; j++ )
        {
            if( edges[i][j] )
            {
                printf( " %d", edges[i][j] );
                totalAdjacents[i]++;
                degrees[edges[i][j]].inDegree++;
                degrees[i].outDegree++;
            }
        }

        cout << endl;
    }

    cout << endl << endl;

    for(int i=1; i<=N; i++)
    {
        printf("Total Adjacent Nodes of Node %d => %d\n", i, totalAdjacents[i]);
    }

    cout << endl << endl;

    for(int i=1; i<=N; i++)
    {
        printf("In degree of Node %d => %d\n", i, degrees[i].inDegree);
        printf("Out degree of Node %d => %d\n\n", i, degrees[i].outDegree);
    }

    cout << endl << endl;

    return 0;
}
