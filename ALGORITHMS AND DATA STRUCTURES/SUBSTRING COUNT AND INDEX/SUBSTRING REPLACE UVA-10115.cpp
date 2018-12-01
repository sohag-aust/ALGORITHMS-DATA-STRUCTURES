#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;

    while(cin>>n)
    {
        if(!n) break;
        cin.ignore();

        vector<string>v;
        unordered_map<string,string>mp;
        string s1,s2;

        int extra = 0;

        for(int i=0;i<n;i++)
        {
            getline(cin,s1);
            getline(cin,s2);

            if(s2.size() == 0) extra = 1;

            v.push_back(s1);
            mp[s1] = s2;
        }

        string target;
        getline(cin,target);

        int flag = 0;
        int i = 0;

        while(i<n)
        {
            string temp = v[i];

            size_t ind = -temp.size();

            flag = 0;

            while(true)
            {
                ind = target.find(temp,ind+temp.size());

                if(ind == string::npos) break;

                else
                {
                    int sz = temp.size();

                    target.replace(ind,sz,mp[temp]);
                    ind += sz;

                    flag = 1;
                }
            }

            if(!flag) i++;
        }

        cout<<target<<endl;

        if(extra) cout<<endl;
    }

    return 0;
}
