#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout<<"Enter a number: ";
    cin>>n;

    int result = n;

    for(int i=2;i*i<=n;i++) /// i*i dici karon kono songkhake i*i range er baire onno kono songkha die take kokhonoi vag kora jabena
    {
        if(n%i == 0)
        {
            result -= result/i;
        }

        while(n%i==0)
        {
            n /= i;
        }
    }

    /// n er value 1 hobe jokhon prime factorization e value er ghat 1 er besi hbe
    /// like 36 = 2^2 * 3^3;; eikhane 2 er sob ghat and 3 er sob ghat die n ke vag krte thakle
    /// n er value 1 e asbe...
    /// jodi ghat konotar 1 ta thake tobe n ke vag krte thakle obossoi sesh e n akta prime number hbe cz tahole
    /// for loop e i*i er value n er cea besi hoe jabe
    /// and tai amra result theke 1 minus krbo..
    /// like 35 = 5*7 eikhane ghat konotai 1 er besi nai tai sesh e n obossoi akta prime number hbe..

    cout<<"n: "<<n<<endl;
    if(n>1) result -= result/n;

    cout<<"cnt: "<<result<<endl;

    return 0;
}
