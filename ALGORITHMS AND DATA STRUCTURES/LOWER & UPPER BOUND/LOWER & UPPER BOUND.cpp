#include<bits/stdc++.h>
using namespace std;

multiset<int>::iterator first_less_than(const multiset<int> &ms,int value)
{
    auto it4 = ms.lower_bound(value);

    if(it4 == ms.end()) --it4; /// jodi set er end k point kore tahole iterator komate hbe
    while(it4 != ms.begin() && *it4 >= value) --it4;

    return (*it4 >= value) ? ms.end() : it4;
}

int main()
{
    vector<int>v = {1,3,5,8,12};
    bool ans = binary_search(v.begin(),v.end(),5); /// binary search kore dekhlam 5 ace kina vector e..
    cout<<"ACE ? : "<<ans<<endl;

    /// akhon lower bound use kore dekhbo je akta value er soman ba tar cea next boro value ta ki vector e ace naki nai...
    /// eta akta iterator return kore.

    auto it = lower_bound(v.begin(),v.end(),6); /// 6 er next boro ba soman kon value ace vector e...
    cout<<"Next Value: "<<*it<<endl;

    /// akhon dekhbo next boro value ta koto number index e ace..

    int index_first = distance(v.begin(),it); /// iterator ta kon index e ace. eta die amra akta value er first occurance index ber krte pari.
    cout<<"Index: "<<index_first<<endl;

    /// distance function use na kore amra minus kore krte pari..
    index_first = it - v.begin();
    cout<<"Index: "<<index_first<<endl;

    /// akhon lower bound use kore dekhbo desired value theke boro element kothai ace.. not soman or boro.. sudhu boro..

    vector<int>v1 = {1,3,5,5,5,5,12};

    auto it1 = upper_bound(v1.begin(),v1.end(),5);
    cout<<"Next Value: "<<*it1<<endl;

    it1 = upper_bound(v1.begin(),v1.end(),45);
    if(it1 == v1.end()) cout<<"Value not found"<<endl;

    /// akhon upper bound die akta value er last occurance mane last kon index e ace seta ber krte pari.
    it1 = upper_bound(v1.begin(),v1.end(),5);
    cout<<"Last index: "<<distance(v1.begin(),(--it1))<<endl; /// upper bound akta value next boro value ta return kore tai index paite hoile amader iterator take akbar minus krte hbe.
    ++it1; /// upore it1-- korci tai barai die nicer poddhoti onushoron krlam.
    int index_last = (--it1) - v1.begin();
    cout<<"Last index: "<<index_last<<endl;

    /// akhon vector ta set er moddhe nie amra lower bound ans upper bound ber krte parbo..

    set<int>st(v.begin(),v.end());
    auto it2 = st.lower_bound(5);
    cout<<"Lower bound value: "<<*it2<<endl;

    it2 = st.upper_bound(5);
    cout<<"Upper bound value: "<<*it2<<endl;


    /// akhon amra first less than value ta ber korbo

    vector<int>v4 = {1,3,3,3,3,5,8,8,8,9,12};
    multiset<int>s(v4.begin(),v4.end());
    auto it5 = first_less_than(s,7);

    if(it5 == s.end()) cout<<"Not Found";
    else cout<<"First less value: "<<*it5;
    puts("");

    return 0;
}

