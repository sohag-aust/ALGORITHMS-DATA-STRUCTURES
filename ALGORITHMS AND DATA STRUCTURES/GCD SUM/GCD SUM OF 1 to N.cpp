#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int result = n;
    for(int i = 2; i*i <= n; i++)
    {
        if( n%i == 0) result = result - result/i;
        while( n%i == 0) n /= i;
    }
    if( n>1 )result = result - result/n;
    return result;
}

int gcd_sum(int n)
{
    int sum = 0;
    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0) // found divisor
        {
            int div = i;
            int res = n/i;
            sum += phi(n/div) * i;
            if( div != res)
                sum += phi(n/res) * (n/i);
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << gcd_sum(n) << endl;

    return 0;
}
