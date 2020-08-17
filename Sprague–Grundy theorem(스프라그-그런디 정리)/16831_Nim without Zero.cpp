#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int f(vector<int> v)
{
	int ret = 0;
	for(auto i : v) ret ^= i;
	return ret;
}

bool only_even(vector<int> v)
{
	for(auto i : v)
        if(i%2 == 1) return false;
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &i : v) cin>>i;
	int ret=f(v);
	if(ret > 1) cout<<"Alice";
	else if(ret == 1) cout<<"Bob";
	else
    {
		if(only_even(v)) cout<<"Bob";
		else cout<<"Alice";
	}
}
