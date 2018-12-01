/// TUT : INFIX TO POSTFIX : https://www.youtube.com/watch?v=RETqM5nr2F0

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
        getline(cin,pre);

        stack<char>st;
        string post = "";

        for(auto i : in)
        {
            if(isalpha(i))
                post += i;

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
                        post += top;
                        st.pop();
                        st.push(i);
                    }
                }
            }
        }

        while(!st.empty())
        {
            char top = st.top();
            post += top;
            st.pop();
        }

        cout<<"INFIX   => "<<in<<endl;
        cout<<"PREFIX  => "<<pre<<endl;
        cout<<"POSTFIX => ";

        for(int i=0;i<post.size();i++)
        {
            if(i == post.size()-1) cout<<post[i];
            else cout<<post[i]<<" ";
        }

        cout<<endl;
    }

    return 0;
}

