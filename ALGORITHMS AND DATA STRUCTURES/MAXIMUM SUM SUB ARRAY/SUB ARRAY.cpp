
/// KADANE'S ALGORITHM
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout<<"Enter the size of the array: ";
    cin>>n;

    int ara[n+5];

    cout<<"\nEnter the elements in the array: ";

    for(int i=0;i<n;i++) cin>>ara[i];

    int maximum,sum;

    maximum = ara[0];
    sum = 0;

    int start_index,end_index,search_index;

    start_index = end_index = search_index = 0;

    for(int i=0;i<n;i++)
    {
        sum = sum + ara[i];

        if(maximum < sum)
        {
            maximum = sum;

            start_index = search_index;
            end_index = i;
        }

        if(sum < 0)
        {
            sum = 0;
            search_index = i+1;
        }
    }

    cout<<"\nMaximum Sum: "<<maximum<<endl;
    cout<<"\nMaximum Sub Array -> "<<endl;

    for(int i=start_index; i<=end_index; i++)
    {
        cout<<ara[i]<<" ";
    }

    cout<<endl;

    cout<<"\nLength Of the Sub Array: "<<(end_index - start_index)+1<<endl;

    return 0;
}

/**
INPUT:

16
4 -3 -2 2 3 1 -2 -3 4 2 -6 -3 -1 3 1 2

*/

/**

OUTPUT:

Maximum Sum: 7

Maximum Sub Array ->
2 3 1 -2 -3 4 2

Length Of the Sub Array: 7

*/
