/// UVA - 105
/// TUTORIAL - https://www.youtube.com/watch?v=GSBLe8cKu0s
/// ekhane priority queue er add, remove and insert kora hoice jate nlog(n) time lage. ja amra java treemap er sahajje krte pari.. same time e lage

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

/// CASES
/**
x h y
/**
1 3 3
2 4 4
5 2 8
6 4 7
8 4 9
*/

/**
x h y
/**
0 2 1
0 3 2
3 3 5
4 2 5
6 2 7
7 3 8
*/
/**
1  11  5
2  6  7
3  13  9
12  7  16
14  3  25
19  18  22
23  13  29
24  4  28
*/
