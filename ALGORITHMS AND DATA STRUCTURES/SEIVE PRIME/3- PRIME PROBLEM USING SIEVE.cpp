/// https://icpcarchive.ecs.baylor.edu/external/72/7235.pdf

#include<bits/stdc++.h>
using namespace std;

const int maxi=1000;
bool visit[maxi+2];
vector<int>v[maxi+2];

void pre()
{
    memset(visit,false,sizeof(visit));

    for(int i=3; i*i<=maxi; i+=2)
    {
        if(!visit[i])
        {
            for(int j=i*i; j<=maxi; j+=i)
                visit[j]=true;
        }
    }

    for(int k=6; k<=maxi; k++)
    {
        v[k].push_back(2);

        for(int i=3; i<k; i+=2)
        {
            if(!visit[i])
                v[k].push_back(i);
        }
    }
}

int main()
{
    pre();

    int n,test;
    cin>>test;

    while(test--)
    {
        cin>>n;
        int flag=0;

        for(int i=0; i<v[n].size(); i++)
        {
            for(int j=0; j<v[n].size(); j++)
            {
                for(int k=0; k<v[n].size(); k++)
                {
                    int sum=v[n][k]+v[n][j]+v[n][i];

                    if(sum==n)
                    {
                        cout<<v[n][i]<<" "<<v[n][j]<<" "<<v[n][k]<<endl;
                        flag=1;
                        break;
                    }
                }

                if(flag) break;
            }

            if(flag) break;
        }

        if(!flag) cout<<"0"<<endl;
    }

    return 0;
}
