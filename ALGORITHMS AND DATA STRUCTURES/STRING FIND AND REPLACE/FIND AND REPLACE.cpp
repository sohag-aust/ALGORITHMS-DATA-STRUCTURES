#include<bits/stdc++.h>
using namespace std;


int main ()
{

    string parentstring = "Hello Agnosticdev, I love Tutorials";
    string substring = "Agnosticdev";

    int index = parentstring.find(substring);

    if (index)
    {
        cout << "Substring found at index " << index << ", with length " << substring.length() << endl;
        int val = substring.length();
        parentstring.replace(index,val,"shohag");

        cout<<"NEW: "<<parentstring<<endl;
    }
    else
    {
        cout << "Substring not found at all in parent string" << endl;
    }

    return 0;
}

