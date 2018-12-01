#include<bits/stdc++.h>
using namespace std;

struct argentine
{
    string name;
    int attack;
    int defense;
} team[11];

struct formation
{
    string name;
} new_team[6];

bool cmp(argentine a,argentine b)
{
    if(a.attack == b.attack)
    {
        if(a.defense == b.defense)
            return a.name < b.name;

        else
            return a.defense < b.defense;
    }

    else
        return a.attack > b.attack;
}

bool cmp1(formation a,formation b)
{
    return a.name < b.name;
}

void init()
{
    for(int i=0; i<6; i++)
    {
        new_team[i].name = "";
    }
}

void init1()
{
    for(int i=0; i<10; i++)
    {
        team[i].name = "";
        team[i].attack = 0;
        team[i].defense = 0;
    }
}

int main()
{
    int test;
    int cs = 0;
    cin>>test;

    while(test--)
    {
        for(int i=0; i<10; i++)
        {
            cin>>team[i].name;
            cin>>team[i].attack;
            cin>>team[i].defense;
        }

        sort(team,team+10,cmp);

        for(int i=0; i<5; i++)
        {
            new_team[i].name = team[i].name;
        }

        sort(new_team,new_team+5,cmp1);

        cout<<"Case "<<++cs<<":";

        cout<<"\n(";

        for(int i=0; i<5; i++)
        {
            if(i == 4)
                cout<<new_team[i].name<<")";

            else
                cout<<new_team[i].name<<", ";
        }

        init();

        for(int i=5; i<10; i++)
        {
            new_team[i-5].name = team[i].name;
        }

        sort(new_team,new_team+5,cmp1);

        cout<<"\n(";

        for(int i=0; i<5; i++)
        {
            if(i == 4)
                cout<<new_team[i].name<<")";

            else
                cout<<new_team[i].name<<", ";
        }

        cout<<endl;

        init();
        init1();
    }

    return 0;
}

