#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node,edge;
    string s,s1,s2;

    while(cin>>node)
    {
        cin.ignore();

        map<string,int>mp1;
        map<int,string>mp2;
        vector<int>v[110];
        map<int,int>indeg;
        vector<int>ans;

        static int cs = 0;

        for(int i=1; i<=node; i++)
        {
            cin>>s;
            mp1[s] = i;
            mp2[i] = s;
        }

        cin>>edge;

        for(int i=1; i<=edge; i++)
        {
            cin>>s1>>s2;

            v[mp1[s1]].push_back(mp1[s2]);
            indeg[mp1[s2]]++;
        }

        while(true)
        {
            for(int i=1; i<=node; i++) /// ordering thik rakar jnno bar bar 1 theke suru krte hocche..
            {
                if(!indeg[i])
                {
                    indeg[i]--;

                    ans.push_back(i);

                    int sz = v[i].size();

                    for(int j=0; j<sz; j++)
                    {
                        indeg[v[i][j]]--;
                    }

                    break;
                }
            }

            if(ans.size() == node) break;
        }

        cout<<"Case #"<<++cs<<": Dilbert should drink beverages in this order: ";

        for(int i=0;i<ans.size();i++)
        {
            if(i<ans.size()-1)
                cout<<mp2[ans[i]]<<" ";
            else
                cout<<mp2[ans[i]]<<".";
        }

        cout<<endl<<endl;
    }

    return 0;
}


/**
5
wine
beer
rum
apple-juice
cachaca
6
beer cachaca
apple-juice beer
apple-juice rum
beer rum
beer wine
wine cachaca
*/

