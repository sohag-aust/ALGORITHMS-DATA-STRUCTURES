/// WE USE BITSET BECAUSE IT IS MORE MEMORY EFFICIENT.
/// BIT SET ER PROTITA BIT 1 BIT KORE JAIGA NEI.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    bitset<6>bit; /// amader first ei bitset er size die dite hbe.
    /// bit set er indexing right(LSB) theke left(MSB) te hoi.. 0 based indexing.

    bit.set(); /// bitset er sob bit er moddhe 1 value initialize hoe gelo.
    cout<<"After set bitset value: "<<bit<<endl;

    bit.reset(); /// bitset er sob bit er moddhe 0 value initialize hoe gelo.
    cout<<"After reset bitset value: "<<bit<<endl;

    /// akhon jodi amra kono particular index er value change krte cai then..
    bit.set(1); /// akhon index 1 er value 1 hbe..
    bit.set(3); /// akhon index 3 er value 1 hbe..
    bit[4] = 1; /// evabe o index er value change kora jai..

    cout<<"\nAfter setting particular index value -> "<<bit<<endl;

    /// akhon jodi amra dekhte cai ba test korte cai kon index e kon bit ace either 0 or 1 ta amra dekhte parbo.
    cout<<"\nTest bitset value -> "<<endl;
    for(int i=0;i<bit.size();i++)
    {
        cout<<bit.test(i)<<endl;
    }

    /// akhon jodi amra bitset e koita 1 value ace seta count krte cai tahole...
    cout<<"\nNumber of 1 in bitset: "<<bit.count()<<endl;

    /// akhon jodi amra bitset e koita 0 value ace seta count krte cai tahole...
    cout<<"Number of 0 in bitset: "<<bit.size() - bit.count()<<endl;

    /// akhon jodi amra check korte cai bitset e kono 1 ace kina...
    cout<<"\nIs there any 1 in bitset ? = "<<bit.any()<<endl; /// thakle 1 return krbe na hole 0 return krbe..

    /// akhon jodi amra check korte cai bitset puro ta khali kina.. mane all bit 0 kina..
    cout<<"Is the bitset hold all zero ? = "<<bit.none()<<endl; /// jodi sob 0 thake tahole 1 return krbe na hole 0 return krbe.

    /// akhon jodi amra check korte cai sob gula bit e 1 ace kina...
    cout<<"Are all the bit is 1 in bitset ? = "<<bit.all()<<endl; /// jodi sob 1 thake tahole 1 return krbe na hole 0 return krbe.

    /// akhon jodi amra bitset er bit gula change krte cai like jekhane 1 ace setake 0 and jekhane 0 ace setake 0 krte cai tahole.
    /// ex: 1010 ace amra etake 0101 krte cai.
    cout<<"\nChanging the bits in bitset: "<<bit.flip()<<endl;

    /// akhon amra bitset er binary value take decimal e nite cai then...
    cout<<"\nConverting the value to decimal: "<<bit.to_ulong()<<endl;

    /// akhon amra bitset er binary value take string e convert krte cai then...
    cout<<"\nConverting the value to string: "<<bit.to_string()<<endl;


    /// bitset er moddhe amra string die o bit set kore dite pari.. like..
    bitset<6>bit1(string("101010"));
    cout<<"\nNew Bitset using string value: "<<bit1<<endl;

    return 0;
}
