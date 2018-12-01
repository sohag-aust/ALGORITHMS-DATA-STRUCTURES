#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text,find;

    cout<<"Enter a text: ";
    cin>>text;

    cout<<"Enter a string to convert: ";
    cin>>find;

    int text_len=text.size();
    int find_len=find.size();

    int dp[text_len+2][find_len+2];

    for(int i=0; i<=text_len; i++)
    {
        for(int j=0; j<=find_len; j++)
        {
            if(i==0) dp[i][j]=j;
        }

        if(i>0) dp[i][0]=i;
    }

    int left,up,diag;
    left=up=diag=0;

    pair<int,int>p;
    map<pair<int,int>,char>parent;

    for(int i=1; i<=text_len; i++)
    {
        for(int j=1; j<=find_len; j++)
        {
            p=make_pair(i,j);

            if(text[i-1]==find[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
                parent[p]='d';
            }

            else
            {
                int left=dp[i][j-1];
                int up=dp[i-1][j];
                int diag=dp[i-1][j-1];

                if(left<=up && left<=diag)
                {
                    dp[i][j]=left+1;
                    parent[p]='L';
                }

                else if(up<=left && up<=diag)
                {
                    dp[i][j]=up+1;
                    parent[p]='U';
                }

                else
                {
                    dp[i][j]=diag+1;
                    parent[p]='D';
                }
            }
        }
    }

    cout<<"\n\nDP TABLE ->> "<<endl;

    for(int i=0; i<=text_len; i++)
    {
        for(int j=0; j<=find_len; j++)
        {
            if(i==0 || j==0)
                cout<<dp[i][j]<<" ";
            else
            {
                p=make_pair(i,j);
                cout<<dp[i][j]<<parent[p]<<" ";
            }
        }

        cout<<endl;
    }

    cout<<endl;

    int i=text_len;
    int j=find_len;

    cout<<"\n** Total operation needed : "<<dp[i][j]<<endl;

    vector<pair<char,char> >convert;
    pair<char,char>pc;
    vector<char>in,del;

    while(i && j)
    {
        p=make_pair(i,j);

        if(parent[p]=='d')
        {
            i--,j--;
        }

        else if(parent[p]=='D')
        {
            i--,j--;
            pc=make_pair(text[i],find[j]);
            convert.push_back(pc);
        }

        else if(parent[p]=='L')
        {
            j--;
            in.push_back(find[j]);
        }

        else if(parent[p]=='U')
        {
            i--;
            del.push_back(text[i]);
        }
    }

    cout<<"\n** Convert operation ->: "<<convert.size()<<endl;

    for(int i=0; i<convert.size(); i++)
        cout<<"\t"<<i+1<<" : "<<convert[i].first<<" -> "<<convert[i].second<<endl;


    cout<<"\n** Insert operation ->: "<<in.size()<<endl;

    for(int i=0; i<in.size(); i++)
        cout<<"\t"<<i+1<<" -> "<<in[i]<<endl;

    cout<<"\n** Delete operation ->: "<<del.size()<<endl;

    for(int i=0; i<del.size(); i++)
        cout<<"\t"<<i+1<<" -> "<<del[i]<<endl;

    cout<<"\n\n ->> NB: UP (U) for remove..\n\t LEFT (L) for insert.. \n\t DIAGONAL (D) for convert.."<<endl;

    return 0;
}


/**
ALGORITHM
ALTRUISTIC
*/

