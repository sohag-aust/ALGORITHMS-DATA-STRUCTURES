#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Number of Item: ";
    int item;
    cin>>item;
    int weight[item+2];
    int cost[item+2];

    for(int i=0; i<item; i++)
    {
        puts("");
        cout<<i+1<<"'th item weight: ";
        cin>>weight[i];
        cout<<i+1<<"'th item cost: ";
        cin>>cost[i];
    }

    cout<<"\nEnter the highest weight: ";
    int w;
    cin>>w;

    int ara[item+2][w+2];

    for(int i=0; i<=item; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0 || j==0)
                ara[i][j]=0;
        }
    }

    int k=0;

    for(int i=1; i<=item; i++,k++)
    {
        for(int j=1; j<=w; j++)
        {
            int val1=0;
            int wi=weight[i-1];

            if(j>=wi)
            {
                val1=cost[k]+(ara[i-1][j-wi]);
            }

            int val2=ara[i-1][j];

            ara[i][j]=max(val1,val2);
        }
    }

    puts("\nKnapsack Table ->> \n");

    for(int i=0; i<=item; i++)
    {
        for(int j=0; j<=w; j++)
            cout<<ara[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nTotal profit: "<<ara[item][w]<<endl;

    return 0;
}

