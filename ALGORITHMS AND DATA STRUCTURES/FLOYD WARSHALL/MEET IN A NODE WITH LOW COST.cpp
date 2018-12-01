/// UVA - 10171

#include<bits/stdc++.h>
using namespace std;

#define sz 26
#define inf 1e9

map<char,int>mp;
int manzoor[sz+2][sz+2];
int miguel[sz+2][sz+2];

void init()
{
    int k = 0;

    for(char ch='A'; ch<='Z'; ch++)
        mp[ch] = ++k;

    memset(manzoor,0,sizeof(manzoor));
    memset(miguel,0,sizeof(miguel));

    for(int i=1; i<=sz; i++)
    {
        for(int j=1; j<=sz; j++)
        {
            if(i == j)
            {
                manzoor[i][j] = 0;
                miguel[i][j] = 0;
            }

            else
            {
                manzoor[i][j] = inf;
                miguel[i][j] = inf;
            }
        }
    }
}

void manzoor_floyd()
{
    for(int k=1; k<=sz; k++)
    {
        for(int i=1; i<=sz; i++)
        {
            for(int j=1; j<=sz; j++)
            {
                if(manzoor[i][k] + manzoor[k][j] < manzoor[i][j])
                    manzoor[i][j] = manzoor[i][k] + manzoor[k][j];
            }
        }
    }
}

void miguel_floyd()
{
    for(int k=1;k<=sz;k++)
    {
        for(int i=1;i<=sz;i++)
        {
            for(int j=1;j<=sz;j++)
            {
                if(miguel[i][k] + miguel[k][j] < miguel[i][j])
                    miguel[i][j] = miguel[i][k] + miguel[k][j];
            }
        }
    }
}

int main()
{
    int node;

    while(cin>>node,node)
    {
        mp.clear();
        init();

        while(node--)
        {
            char age,dir,u,v;
            int w;

            cin>>age>>dir>>u>>v>>w;

            if(age == 'Y')
            {
                manzoor[mp[u]][mp[v]] = w;

                if(dir == 'B')
                    manzoor[mp[v]][mp[u]] = w;
            }

            else
            {
                miguel[mp[u]][mp[v]] = w;

                if(dir == 'B')
                    miguel[mp[v]][mp[u]] = w;
            }
        }

        manzoor_floyd();
        miguel_floyd();

        char man_start,mig_start;
        cin>>man_start>>mig_start;

        manzoor[mp[man_start]][mp[man_start]] = 0;
        miguel[mp[mig_start]][mp[mig_start]] = 0;

        int mini = inf;

        for(int i=1;i<=sz;i++)
            mini = min(mini, manzoor[mp[man_start]][i] + miguel[mp[mig_start]][i]);

        if(mini == inf)
            cout<<"You will never meet.";

        else
        {
            vector<char>ans;

            for(int i=1;i<=sz;i++)
            {
                if(mini == manzoor[mp[man_start]][i] + miguel[mp[mig_start]][i])
                    ans.push_back((char)i+64);
            }

            cout<<mini;

            sort(ans.begin(),ans.end());

            for(auto it=ans.begin();it<ans.end();it++)
                cout<<" "<<*it;
        }

        cout<<endl;
    }

    return 0;
}

