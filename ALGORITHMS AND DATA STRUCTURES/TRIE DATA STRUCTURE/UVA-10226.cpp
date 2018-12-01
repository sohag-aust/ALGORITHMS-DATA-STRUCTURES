#include<bits/stdc++.h>
using namespace std;

int id;

struct node
{
    bool endmark;
    node* ara[54];

    node()
    {
        endmark = false;

        for(int i=0; i<53; i++)
            ara[i] = NULL;
    }

}*root;

void insert(string str,int sz)
{
    node* curr = root;

    for(int i=0; i<sz; i++)
    {
        if(isupper(str[i]))
            id = str[i]-'A';

        else if(islower(str[i]))
        {
            id = str[i]-'a';
            id = id+26;
        }

        else if(isspace(str[i]))
        {
            id = str[i]-32;
            id = id+52;
        }

        if(curr->ara[id] == NULL)
        {
            curr->ara[id] = new node();
        }

        curr = curr->ara[id];
    }

    curr->endmark = true;
}

bool search(string str,int sz)
{
    node* curr = root;

    for(int i=0;i<sz;i++)
    {
        if(isupper(str[i]))
            id = str[i]-'A';

        else if(islower(str[i]))
        {
            id = str[i]-'a';
            id = id+26;
        }

        else if(isspace(str[i]))
        {
            id = str[i]-32;
            id = id+52;
        }

        if(curr->ara[id] == NULL) return false;

        curr = curr->ara[id];
    }

    return curr->endmark;
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
    cin.ignore();
    cin.ignore();

    while(test--)
    {
        root = new node();

        string str;
        vector<string>v;
        map<string,int>mp;
        set<string>st;

        while(getline(cin,str))
        {
            if(str.size() == 0) break;

            v.push_back(str);
        }

        int total = v.size();

        sort(v.begin(),v.end());

        for(int i=0; i<v.size(); i++)
        {
            insert(v[i],v[i].size());
        }

        for(int i=0; i<v.size(); i++)
        {
            if(search(v[i],v[i].size()))
            {
                st.insert(v[i]);
                mp[v[i]]++;
            }
        }

        set<string>::iterator it = st.begin();

        while(it!=st.end())
        {
            cout<<*it<<" ";

            double res = ((double)mp[*it]/(double)total)*(double)100;

            cout<<setprecision(4)<<fixed<<res<<endl;

            it++;
        }

        if(test) cout<<endl;

        del(root);
    }

    return 0;
}
