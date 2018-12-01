#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int cnt = 0;

    size_t found = -t.size();

    while(true)
    {
        found = s.find(t, found + t.size());

        if(found == string::npos)
            break;

        else
            cnt++;

        cout<<"SubString found at index: "<<found<<endl;
    }

    cout<<cnt<<endl;

    return 0;
}
