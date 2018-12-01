#include<bits/stdc++.h>
using namespace std;

int node;
int parent[1010];

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


void make_set()
{
    for(int i=0; i<=node; i++)
        parent[i]=i;
}

int find_set(int r)
{
    if(parent[r]==r) return r;
    return parent[r]=find_set(parent[r]);
}

void union_set(int a, int b)
{
    int u=find_set(a);
    int v=find_set(b);

    if(u!=v)
        parent[u]=v;
}

int finding(int a,int b)
{
    int u=find_set(a);
    int v=find_set(b);

    if(u==v) return 1;
    else return 2;
}

int main()
{
    int test;
    cin>>test;
    cin.ignore();

    while(test--)
    {
        int yes,no;
        cin>>node;
        make_set();
        cin.ignore();

        string str;

        yes=no=0;

        while(getline(cin,str))
        {
            if(str.size()==0) break;

            stringstream ss(str);
            string s,ch;
            int a,b;
            int cnt=1;

            while(ss>>s)
            {
                if(cnt==1) ch=s;
                else if(cnt==2) a=(int)parseint(s);
                else b=(int)parseint(s);
                cnt++;
            }

            if(ch=="c")
            {
                union_set(a,b);
            }

            else if(ch=="q")
            {
                int value = finding(a,b);

                if(value==1) yes++;
                else no++;
            }
        }

        cout<<yes<<","<<no<<endl;
        if(test) cout<<endl;
    }

    return 0;
}

