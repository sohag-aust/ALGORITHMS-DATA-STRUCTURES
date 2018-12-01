#include<bits/stdc++.h>
using namespace std;

int fTable[1000];
int ret;

void LPS(string pat)
{
    int sz = pat.size();

    int i,j;

    i = 1;
    j = 0;

    fTable[0] = 0;

    while(i<sz)
    {
        if(pat[i] == pat[j])
        {
            j++;
            fTable[i] = j;
            i++;
        }

        else
        {
            if(j) j = fTable[j-1];

            else
            {
                fTable[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string text,string pat)
{
    int i,j;

    i = j = 0;

    int sz = text.size();

    while(i<sz)
    {
        if(text[i] == pat[j])
        {
            i++;
            j++;
        }

        if(j == pat.size())
        {
            ret = i-j;
            cout<<"Found At Position: "<<ret<<"."<<endl;
            j = fTable[j-1];
        }

        else if(i<sz && text[i] != pat[j])
        {
            if(j) j = fTable[j-1];
            else i++;
        }
    }
}

int main()
{
    string text,pat;

    cin>>text>>pat;

    ret = -1;

    LPS(pat);
    KMP(text,pat);

    if(ret == -1) cout<<"Not Found"<<endl;

    return 0;
}
