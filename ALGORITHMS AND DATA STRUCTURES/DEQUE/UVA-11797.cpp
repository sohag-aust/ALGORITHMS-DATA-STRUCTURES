#include<bits/stdc++.h>
using namespace std;

#define sz 5

map<string,int>mp;
int sum[sz+2];

void init()
{
    mp["Ja"] = 0, mp["Sam"] = 1, mp["Sha"] = 2, mp["Sid"] = 3, mp["Tan"] = 4;
}

int main()
{
    init();

    int test,cs=0;
    cin>>test;

    while(test--)
    {
        memset(sum,0,sizeof(sum));

        deque<string>dq[sz+2];
        string top;
        int m,n;

        cin>>m>>n>>top;

        for(int i=0; i<sz; i++)
        {
            int k;
            cin>>k;

            for(int j=0; j<k; j++)
            {
                string str;
                cin>>str;
                dq[i].push_back(str);
            }
        }

        int spend = 2;

        while(n>0)
        {
            int ind = mp[top];

            sum[ind] += min(m,n);
            n -= min(m,n);
            n -= min(n,spend);
            top = dq[ind].front();
            dq[ind].pop_front();
            dq[ind].push_back(top);
        }

        cout<<"Case "<<++cs<<":"<<endl;

        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            cout<<it->first<<" "<<sum[it->second]<<endl;
        }
    }

    return 0;
}

