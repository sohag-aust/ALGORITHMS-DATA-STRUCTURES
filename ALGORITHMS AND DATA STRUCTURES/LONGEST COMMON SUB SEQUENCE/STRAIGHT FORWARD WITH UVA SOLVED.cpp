#include<bits/stdc++.h>
using namespace std;

vector<char>v;

int main()
{
    string x,y;
    int lx,ly;

    while(getline(cin,x))
    {
        getline(cin,y);

        lx=x.size();
        ly=y.size();

        int ara[lx+2][ly+2];

        for(int i=0; i<=lx; i++)
        {
            for(int j=0; j<=ly; j++)
            {
                if(i==0 || j==0)
                    ara[i][j]=0;

                else if(x[i-1]==y[j-1])
                {
                    ara[i][j]=(ara[i-1][j-1])+1;
                }

                else
                {
                    int val1=ara[i-1][j];
                    int val2=ara[i][j-1];

                    ara[i][j]=max(val1,val2);
                }
            }
        }

        cout<<"\nDP TABLE->>\n";

        for(int i=0;i<=lx;i++)
        {
            for(int j=0;j<=ly;j++)
            {
                cout<<ara[i][j]<<" ";
            }

            cout<<endl;
        }


        int i,j;
        i=lx,j=ly;

        while(i && j)
        {
            if(x[i-1]==y[j-1])
            {
                v.push_back(x[i-1]);
                i--;
                j--;
            }

            else if(ara[i-1][j]>ara[i][j-1])
                i--;

            else
                j--;
        }


        reverse(v.begin(),v.end());

        cout<<"sequence: ";
        for(int i=0;i<v.size();i++)
            cout<<v[i];
        cout<<endl;

        v.clear();
    }

    return 0;
}
