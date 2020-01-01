#include<bits/stdc++.h>
using namespace std;
map<pair<string, string>, int>mp;

int main() 
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	long long ans = 0;
	cin>>n;
	for (int i = 0; i < n; i++) 
    {
		string a, b;
		cin >> a >> b;
		a = a.substr(0, 2);
		if (a == b) continue;
		if (mp.find({ b,a })!=mp.end())
            ans += mp[{b, a}];
		if (mp.find({ a,b })!=mp.end())
            mp[{a, b}] = mp[{a, b}] + 1;
		else mp[{a, b}] = 1;
	}
	cout <<ans;
}