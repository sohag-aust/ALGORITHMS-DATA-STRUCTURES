#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x1,y1,x11,y11;
    int x2,y2,x22,y22;
    int test;

    cin>>test;
    cin.ignore();

    while(test--)
    {
        cin>>x1>>y1>>x11>>y11;
        cin>>x2>>y2>>x22>>y22;

        x1 = max(x1,x2);
        y1 = max(y1,y2);
        x11 = min(x11,x22);
        y11 = min(y11,y22);

        if(x1 >= x11 || y1 >= y11) /// x1 and x11 checks jodi pasapasi overlap na hoi and y1 and y11 checks jodi upore niche overlap na hoi.
            cout<<"No Overlap"<<endl;
        else
            cout<<x1<<" "<<y1<<" "<<x11<<" "<<y11<<endl;

        if(test) cout<<endl;
    }

    return 0;
}
