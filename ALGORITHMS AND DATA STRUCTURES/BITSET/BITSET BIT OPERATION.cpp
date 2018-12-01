#include<bits/stdc++.h>
using namespace std;

int main ()
{
  bitset<4> foo (string("1001"));
  bitset<4> bar (string("0011"));

  cout << (foo^=bar) << '\n';       /// 1010 (XOR,assign)
  cout << (foo&=bar) << '\n';       /// 0010 (AND,assign)
  cout << (foo|=bar) << '\n';       /// 0011 (OR,assign)

  cout << (foo<<=2) << '\n';        /// 1100 (SHL,assign)
  cout << (foo>>=1) << '\n';        /// 0110 (SHR,assign)

  cout << (~bar) << '\n';           /// 1100 (NOT)
  cout << (bar<<1) << '\n';         /// 0110 (SHL)
  cout << (bar>>1) << '\n';         /// 0001 (SHR)

  cout << (foo==bar) << '\n';       /// false (0110==0011)
  cout << (foo!=bar) << '\n';       /// true  (0110!=0011)

  cout << (foo&bar) << '\n';        /// 0010
  cout << (foo|bar) << '\n';        /// 0111
  cout << (foo^bar) << '\n';        /// 0101

  return 0;
}
