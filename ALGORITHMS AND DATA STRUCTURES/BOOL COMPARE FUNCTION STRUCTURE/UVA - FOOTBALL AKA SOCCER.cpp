#include<bits/stdc++.h>
using namespace std;

#define CLR(a) memset(a,0,sizeof(a))

const int maxi=1010,m=100;

int goal_score[m];
int goal_against[m];
int played[m];
map<string,int>mp;
int differ[m];
int point[m];
int win[m];
int lose[m];
int tie[m];

int point_teamA,point_teamB;
int win_teamA,win_teamB;
int g1,g2;

void init()
{
    CLR(goal_score);
    CLR(goal_against);
    CLR(played);
    mp.clear();
    CLR(differ);
    CLR(point);
    CLR(win);
    CLR(lose);
    CLR(tie);
}

struct node
{
    int point_A;
    int win_A;
    int goal_diffA;
    int score_A,gain_A;
    int play_A;
    int lose_A,tie_A;
    char ch_A;
    string team_name;

} football[m];

bool cmp(node one,node two)
{
    if(one.point_A==two.point_A)
    {
        if(one.win_A==two.win_A)
        {
            if(one.goal_diffA==two.goal_diffA)
            {
                if(one.score_A == two.score_A)
                {
                    if(one.play_A==two.play_A)
                    {
                        return one.team_name<two.team_name;
                    }
                    else return one.play_A<two.play_A;
                }
                else return one.score_A>two.score_A;
            }
            else return one.goal_diffA>two.goal_diffA;
        }
        else return one.win_A>two.win_A;
    }
    else return one.point_A>two.point_A;
}

int main()
{
    int test;
    cin>>test;
    cin.ignore();

    while(test--)
    {
        init();

        string tournament;
        getline(cin,tournament);

        int t,m;
        cin>>t;
        cin.ignore();

        string team[t+5];

        for(int i=0; i<t; i++)
        {
            getline(cin,team[i]);
            mp[team[i]]=i;
        }

        cin>>m;
        cin.ignore();

        string match[m+5];

        for(int i=0; i<m; i++)
            getline(cin,match[i]);

        for(int i=0; i<m; i++)
        {
            string s=match[i],go1="",go2="",team1="",team2="";
            int flag=0,flag1=0,cnt=0;

            for(int j=0; j<s.size(); j++)
            {
                if(!flag1 && s[j]!='#') team1+=s[j];
                if(flag1 && s[j]!='#')
                {
                    if(cnt==2) team2+=s[j];
                }
                if(isdigit(s[j]) && !flag) go1+=s[j];
                if(isdigit(s[j]) && flag) go2+=s[j];
                if(s[j]=='@') flag=1;
                if(s[j]=='#')
                {
                    cnt++;
                    flag1=1;
                }
            }

            if(go1.size()==2)
                g1=((go1[0]-'0')*10)+go1[1]-'0';
            else
                g1=go1[0]-'0';

            if(go2.size()==2)
                g2=((go2[0]-'0')*10)+go2[1]-'0';
            else
                g2=go2[0]-'0';

            goal_score[mp[team1]]+=g1;
            goal_against[mp[team1]]+=g2;

            goal_score[mp[team2]]+=g2;
            goal_against[mp[team2]]+=g1;

            point_teamA=point_teamB=0;
            win_teamA=win_teamB=0;

            played[mp[team1]]++;
            played[mp[team2]]++;

            int diff_A=goal_score[mp[team1]]-goal_against[mp[team1]];
            int diff_B=goal_score[mp[team2]]-goal_against[mp[team2]];

            differ[mp[team1]]=diff_A;
            differ[mp[team2]]=diff_B;

            if(g1>g2)
            {
                point[mp[team1]]+=3;
                win[mp[team1]]++;
                lose[mp[team2]]++;
            }

            else if(g2>g1)
            {
                point[mp[team2]]+=3;
                win[mp[team2]]++;
                lose[mp[team1]]++;
            }

            else if(g1==g2)
            {
                point[mp[team1]]+=1;
                point[mp[team2]]+=1;
                tie[mp[team1]]++;
                tie[mp[team2]]++;
            }
        }

        map<string,int>::iterator it=mp.begin();

        while(it!=mp.end())
        {
            football[it->second].point_A=point[it->second];
            football[it->second].win_A=win[it->second];
            football[it->second].lose_A=lose[it->second];
            football[it->second].tie_A=tie[it->second];
            football[it->second].goal_diffA=differ[it->second];
            football[it->second].score_A=goal_score[it->second];
            football[it->second].gain_A=goal_against[it->second];
            football[it->second].play_A=played[it->second];

            string str=it->first;
            char ch=tolower(str[0]);
            football[it->second].ch_A=ch;
            football[it->second].team_name=str;

            it++;
        }

        sort(football,football+t,cmp);

        cout<<tournament<<endl;
        for(int k=0; k<t; k++)
        {
            cout<<k+1<<") "<<football[k].team_name<<" "<<football[k].point_A<<"p, "<<football[k].play_A<<"g ("<<football[k].win_A<<"-"<<football[k].tie_A<<"-"<<football[k].lose_A<<"), "<<football[k].goal_diffA<<"gd ("<<football[k].score_A<<"-"<<football[k].gain_A<<")";
            cout<<endl;
        }

        if(test) cout<<endl;
    }

    return 0;
}

