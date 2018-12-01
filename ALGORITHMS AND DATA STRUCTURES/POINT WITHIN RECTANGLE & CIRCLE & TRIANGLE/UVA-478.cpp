/// point inside circle: tutorial: https://www.youtube.com/watch?v=S6BHQMk8C_A
/// point inside triangle: tutorial: https://www.youtube.com/watch?v=H9qu9Xptf-w

#include<bits/stdc++.h>
using namespace std;

struct node
{
    double x1,x2,x3,y1,y2,y3,rad;
    char id;

    node(char _id,double _x1,double _x2,double _y1,double _y2)
    {
        id=_id;
        x1=_x1, x2=_x2, y1=_y1, y2=_y2;
    }

    node(char _id,double _x1,double _y1,double r)
    {
        id=_id;
        x1=_x1, y1=_y1, rad=r;
    }

    node(char _id,double _x1,double _y1,double _x2,double _y2,double _x3,double _y3)
    {
        id=_id;
        x1=_x1, x2=_x2, x3=_x3, y1=_y1, y2=_y2, y3=_y3;
    }
};

bool check_rectangle(node n,double x,double y)
{
    if((x > n.x1 && x < n.x2) && (y > n.y1 && y < n.y2)) return true;
    return false;
}

bool check_circle(node n,double x,double y)
{
    double _x = (n.x1 - x);
    double _y = (n.y1 - y);
    double r = n.rad;

    if((_x*_x) + (_y*_y) < (r*r)) return true;
    return false;
}

bool check_triangle(node n,double x,double y)
{
    double ABC = fabs((n.x1*((n.y2-n.y3)) + n.x2*((n.y3-n.y1)) + n.x3*((n.y1-n.y2))) / 2.0);
    double PAB = fabs((x*((n.y1-n.y2)) + n.x1*((n.y2-y)) + n.x2*((y-n.y1))) / 2.0);
    double PAC = fabs((x*((n.y3-n.y1)) + n.x1*((y-n.y3)) + n.x3*((n.y1-y))) / 2.0);
    double PBC = fabs((x*((n.y2-n.y3)) + n.x2*((n.y3-y)) + n.x3*((y-n.y2))) / 2.0);

    double diff = (PAB+PAC+PBC) - ABC;

    if(diff < 1e-3) return true; /// reducing precision error.
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    char ch;
    vector<node>v;
    double a,b,c,d,e,f;

    while(cin>>ch && ch!='*')
    {
        if(ch == 'r')
        {
            cin>>a>>b>>c>>d;
            v.push_back(node('r',min(a,c),max(a,c),min(b,d),max(b,d)));
        }

        else if(ch == 'c')
        {
            cin>>a>>b>>c;
            v.push_back(node('c',a,b,c));
        }

        else
        {
            cin>>a>>b>>c>>d>>e>>f;
            v.push_back(node('t',a,b,c,d,e,f));
        }
    }

    while(cin>>a>>b)
    {
        static int cnt = 1;
        if(a == 9999.9 && b == 9999.9) break;

        int flag = 0;
        for(int i=0; i<v.size(); i++)
        {
            node n = v[i];

            if(n.id == 'r')
            {
                if(check_rectangle(n,a,b))
                {
                    flag = 1;
                    cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
                }
            }

            else if(n.id == 'c')
            {
                if(check_circle(n,a,b))
                {
                    flag = 1;
                    cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
                }
            }

            else
            {
                if(check_triangle(n,a,b))
                {
                    flag = 1;
                    cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<endl;
                }
            }
        }

        if(!flag) cout<<"Point "<<cnt<<" is not contained in any figure"<<endl;
        cnt++;
    }

    return 0;
}


