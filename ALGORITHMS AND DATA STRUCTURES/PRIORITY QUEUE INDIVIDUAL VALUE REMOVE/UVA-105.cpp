#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x,h,position;

    node(int _x,int _h,int _i)
    {
        x = _x;
        h = _h;
        position = _i;
    }
};

bool cmp(node a,node b)
{
    if((a.x == b.x) && (a.position == b.position))
    {
        if(a.position == 1) return a.h > b.h;
        return a.h < b.h;
    }

    else if(a.x == b.x) return a.position < b.position;
    return a.x < b.x;
}

template<typename T>
class custom_priority_queue : public priority_queue<T, vector<T>>
{

public:

    bool remove(const T& value)
    {
        auto it = find(this->c.begin(), this->c.end(), value);

        if (it != this->c.end())
        {
            this->c.erase(it);
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }

        else
            return false;
    }
};

int main()
{
    vector<node>v;
    vector<pair<int,int> >ans;
    map<char,int>mp;
    mp['S'] = 1, mp['E'] = 2;
    int x1,h1,y1;

    while(cin>>x1>>h1>>y1)
    {
        v.push_back(node(x1,h1,mp['S']));
        v.push_back(node(y1,h1,mp['E']));
    }

    sort(v.begin(),v.end(),cmp);

    custom_priority_queue<int> pq;
    pq.push(0);
    int maxi = 0;

    for(int i=0; i<v.size(); i++)
    {
        node n = v[i];

        if(n.position == mp['S'])
        {
            pq.push(n.h);

            if(pq.top() > maxi)
            {
                maxi = pq.top();
                ans.push_back({n.x,maxi});
            }
        }

        else
        {
            pq.remove(n.h);
            int top = pq.top();
            if(maxi == top) continue;
            ans.push_back({n.x,top});
            maxi = top;
        }
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second;

        if(i == ans.size()-1) cout<<endl;
        else cout<<" ";
    }

    return 0;
}
