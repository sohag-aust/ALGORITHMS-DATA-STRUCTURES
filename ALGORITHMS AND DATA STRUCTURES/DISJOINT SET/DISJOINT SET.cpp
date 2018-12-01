#include<bits/stdc++.h>
using namespace std;

int par[105];

struct side
{
    int from,to;
} get;

int findset(int r)
{
    if(par[r] == r) return r;
    return par[r] = findset(par[r]);
}

void setunion(int a, int b)
{
    int u = findset(a);
    int v = findset(b);

    if(u == v) printf("They are already friends\n");

    else par[u] = v; /// from shafaet er blog.. jodi e and c friendship krte chai tokhon u hobe d and v hobe b coz  e er representative d and c er ta b..
    /// then amra b ke d er parent kore dibo jar fole c and e friend hoe jabe..
    /// amra par[v]=u     o likhte pari.. tahole d ke b er parent banano hobe r ki...
}
int main()
{
    int u,v,n,a,b,i,j,arr[100] ;
    vector<side> vec;

    scanf("%d",&n);
    for(i = 1; i <= 100; i++)
    {
        par[i] = i;
    }

    for(i = 0; i < n; i++)
    {
        scanf("%d %d",&a,&b);
        get.from =  a;
        get.to   =  b;
        vec.push_back(get);
    }

    for(i = 0; i < n; i++)
    {
        u = vec[i].from;
        v = vec[i].to;
        setunion(u,v);
    }

    for(i = 1; i <= 10; i++) printf("Parent of %d is %d\n", i, par[i]);
    cout << endl;
    for(i = 1; i <= 10; i++) printf("Set of %d is %d\n", i, findset(i));
    cout << endl;
    for(i = 1; i <= 10; i++) printf("Parent of %d is %d\n", i, par[i]);

    return 0;
}
/**

sample input:
6
1 2
2 3
4 5
6 7
10 9
9 8

smaple input:
3
1 2
2 3
3 4
*/

