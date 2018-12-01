#include<bits/stdc++.h>
using namespace std;

const int maxi = 1e6;

int main()
{
    int item;
    cout<<"Enter the number of item: ";
    cin>>item;
    int coin[item+4];

    cout<<"\nEnter the item value -> \n"<<endl;
    for(int j=0; j<item; j++)
    {
        cout<<j+1<<" 'th coin: ";
        cin>>coin[j];
    }

    int poisa;
    cout<<"\nEnter the coin to make: ";
    cin>>poisa;

    int total[poisa+3];
    int track[poisa+3];

    total[0]=0;

    for(int i=1; i<=poisa; i++)
        total[i]=maxi;

    for(int i=0; i<=poisa; i++)
        track[i]=-1;

    for(int j=0; j<item; j++)
    {
        for(int i=0; i<=poisa; i++)
        {
            if(i>=coin[j])
            {
                int mini = min(total[i],(1+total[i-coin[j]]));

                if(mini<total[i])
                    track[i]=j;

                total[i]=mini;
            }
        }

        /**cout<<"\nAfter "<<(j+1)<<" iteration tables like -> "<<endl;
        cout<<"\nTotal Table -> "<<endl;

        for(int k=0; k<=poisa; k++)
            cout<<"("<<k<<")"<<total[k]<<" ";
        cout<<endl;

        cout<<"\nTrack Table -> "<<endl;

        for(int k=0; k<=poisa; k++)
            cout<<"("<<k<<")"<<track[k]<<" ";
        cout<<endl;*/

    }

    cout<<"\nMinimum number of coin to make coin "<<poisa<<" is: "<<total[poisa]<<endl;

    vector<int>v; /// track to selected coins.
    int i=poisa;
    int taka=poisa;

    while(taka!=0)
    {
        int select = track[i];

        v.push_back(coin[select]); /// coin select korchi..

        taka-=coin[select];
        i=taka;
    }

    cout<<"Selected coins to make "<<poisa<<" are -> ";

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<", ";
    cout<<endl;

    return 0;
}

