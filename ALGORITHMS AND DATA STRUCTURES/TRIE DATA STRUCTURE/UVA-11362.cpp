#include<bits/stdc++.h>
using namespace std;

int cnt;

struct node
{
    bool endmark;
    node* ara[11];

    node()
    {
        endmark = false;

        for(int i=0;i<10;i++)
            ara[i] = NULL;
    }

}*root;

int insert(string str,int sz)
{
    node* curr = root;

    for(int i=0;i<sz;i++)
    {
        int id = str[i]-'0';

        if(curr->endmark)
        {
            cnt = 0;
            return cnt;
        }

        if(curr->ara[id] == NULL)
        {
            curr->ara[id] = new node();
        }

        curr = curr->ara[id];
    }

    curr->endmark = true;

    return 1;
}

void del(node* cur)
{
    for (int i = 0; i < 10; i++)
    {
        if (cur->ara[i])
            del(cur->ara[i]);
    }

    delete (cur);
}

int main()
{
    int test;
    cin>>test;

    while(test--)
    {
        root = new node();

        int n;
        cin>>n;

        string str;
        vector<string>v;

        for(int i=0;i<n;i++)
        {
            cin>>str;
            v.push_back(str);
        }

        sort(v.begin(),v.end());

        int flag = 1;

        for(int i=0;i<v.size();i++)
        {
            cnt = 1;

            int res = insert(v[i],v[i].size());

            if(!res)
            {
                flag=0;
                break;
            }
        }

        if(flag) cout<<"YES";
        else cout<<"NO";

        cout<<endl;

        del(root);
    }

    return 0;
}

