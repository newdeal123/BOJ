#include <bits/stdc++.h>
using namespace std;
const int MOD = 2014;

map<string, int> lookup;

int f(string s)
 {
  int&ret=lookup[s];
    if(ret!=0) return ret;
    ret=1;
  int len = s.length();
    for(int i = 1; i * 2 < len ; ++i)
    {
        if(s.substr(0, i) == s.substr(i, i))
        ret += f(s.substr(i, len - i))%MOD;
        
        if(s.substr(0, i) == s.substr(len - i, i))
        ret += f(s.substr(i, len - i))%MOD;

        if(s.substr(0, i) == s.substr(len - i, i))
        ret += f(s.substr(0, len - i))%MOD;

        if(s.substr(len - i * 2, i) == s.substr(len - i, i))
        ret += f(s.substr(0, len - i))%MOD;
  }
  return ret%MOD;
}

int main()
 {
  string s;
  cin >> s;
  cout <<(f(s)-1) % MOD;
  return 0;
}
