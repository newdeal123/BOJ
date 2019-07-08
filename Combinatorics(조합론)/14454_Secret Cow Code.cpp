#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

char f(ll k,ll Range)
{
	if (k == s.size())return Range;
	if (Range < k/2)return f(k/2, Range);

	if(Range-k/2<1) return f(k/2,Range-1);
	else return f(k/2,Range-k/2-1);
}
int main()
{
	ll n, m;
	cin>>s>>n;
	n--;
	m = s.size();
	while (m <= n)
		m *= 2;
	cout<<s[f(m,n)];
}
