/// TUT : INFIX TO PREFIX : https://www.youtube.com/watch?v=UK16ttNfGSk

#include<bits/stdc++.h>
using namespace std;

multimap<char,int>mp;

void init()
{
    mp.insert({'!',1});
    mp.insert({'|',2});
    mp.insert({'&',2});
    mp.insert({'-',3});
    mp.insert({'+',3});
    mp.insert({'/',4});
    mp.insert({'*',4});
    mp.insert({'$',5});
}

int main()
{
    init();

    string in,pre;

    while(getline(cin,in))
    {
        string infix = in;
        reverse(in.begin(),in.end());

        stack<char>st;
        pre = "";

        for(auto i : in)
        {
            if(isalpha(i))
                pre += i;

            else if(i != ' ')
            {
                if(st.empty()) st.push(i);

                else
                {
                    char top = st.top();

                    if(mp.find(i)->second >= mp.find(top)->second)
                        st.push(i);

                    else
                    {
                        pre += top;
                        st.pop();
                        st.push(i);
                    }
                }
            }
        }

        while(!st.empty())
        {
            char top = st.top();
            pre += top;
            st.pop();
        }

        reverse(pre.begin(),pre.end());

        cout<<"INFIX   => "<<infix<<endl;
        cout<<"PREFIX  => ";

        for(int i=0; i<pre.size(); i++)
        {
            if(i == pre.size()-1) cout<<pre[i];
            else cout<<pre[i]<<" ";
        }

        cout<<endl;
    }

    return 0;
}

