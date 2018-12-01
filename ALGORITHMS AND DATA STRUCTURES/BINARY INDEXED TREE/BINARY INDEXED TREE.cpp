#include<bits/stdc++.h>
using namespace std;

int n;

int query(int *tree, int ind)
{
    int sum = 0;

    while(ind > 0)
    {
        sum += tree[ind];
        ind = ind - (ind & (-ind));
    }

    return sum;
}

void updateBIT(int *tree, int n, int ind, int val)
{
    ind++;

    while(ind <= n)
    {
        tree[ind] += val;
        ind = ind + (ind & (-ind));
    }
}

int *constructTree(int *ara, int n)
{
    int *tree = new int [n+2];

    for(int i=1; i<=n; i++)
        tree[i] = 0;

    for(int i=0; i<n; i++)
        updateBIT(tree,n,i,ara[i]);

    return tree;
}

int main()
{
    cout<<"Enter the size of the array: ";
    cin>>n;

    int ara[n+2];

    cout<<"\nEnter the elements in the array.."<<endl;

    for(int i=0; i<n; i++) cin>>ara[i];

    int *tree = constructTree(ara,n);

    int q;

    cout<<"\nEnter the index number to be queried: ";

    while(cin>>q)
    {
        cout<<"\nEnter 0 to break.."<<endl;

        if(q == 0) break;

        int res = query(tree,q);

        cout<<"\nSum of index 1 to "<<q<<" is: "<<res<<endl;
    }

    int change;
    cout<<"\n\nEnter the index number to be changed with new value (0 based indexing array not in the tree array): ";
    cin>>change;

    int value;
    cout<<"\nEnter the new value in the array: ";
    cin>>value;

    updateBIT(tree,n,change,value);

    cout<<"\nAfter Updating.."<<endl;

    cout<<"Enter the index number to be queried: ";

    while(cin>>q)
    {
        cout<<"\nEnter 0 to break.."<<endl;

        if(q == 0) break;

        int res = query(tree,q);

        cout<<"\nSum of index 1 to "<<q<<" is: "<<res<<endl;
    }

    return 0;
}

