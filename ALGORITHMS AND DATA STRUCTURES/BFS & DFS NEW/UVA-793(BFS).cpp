#include<bits/stdc++.h>
using namespace std;

const int maxi=1010;
vector<int>v[maxi];
int visit[maxi],flag;
int node;

void init()
{
    for(int i=0; i<=node; i++)
        v[i].clear();

    for(int i=0; i<=node; i++)
        v[i].push_back(i);

}

int parseint(string s)
{
    int res = 0;
    for(int x=0; x<s.size(); x++)
    {
        if(x == 0)
            res = s[x] - '0';
        else
            res = (res *10) + (s[x] - '0');
    }
    return res;
}

int bfs(int st,int en)
{
    queue<int>q;
    q.push(st);
    visit[st]=1;

    while(!q.empty())
    {
        int frnt=q.front();
        q.pop();

        int sz=v[frnt].size();

        for(int i=0; i<sz; i++)
        {
            int val=v[frnt][i];

            if(val==en)
            {
                flag=1;
                break;
            }

            if(!visit[val])
            {
                visit[val]=1;
                q.push(val);
            }
        }

        if(flag) break;
    }

    return flag;
}

int main()
{
    int test;
    cin>>test;
    cin.ignore();

    while(test--)
    {
        init();

        cin>>node;
        cin.ignore();

        string str,ch;
        int a,b;

        int yes,no;
        yes=no=0;

        while(getline(cin,str))
        {
            if(str.size()==0) break;

            stringstream ss(str);
            string s;

            int cnt=1;

            while(ss>>s)
            {
                if(cnt==1) ch=s;
                else if(cnt==2) a=parseint(s);
                else b=parseint(s);
                cnt++;
            }

            if(ch=="c")
            {
                v[a].push_back(b);
                v[b].push_back(a);
            }

            else if(ch=="q")
            {
                flag=0;
                memset(visit,0,sizeof(visit));

                int value = bfs(a,b);

                if(value) yes++;
                else no++;
            }
        }

        cout<<yes<<","<<no<<endl;
        if(test)cout<<endl;

    }

    return 0;
}
