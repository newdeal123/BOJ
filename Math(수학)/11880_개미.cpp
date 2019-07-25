#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
	cin >> t;
	while(t--)
    {
        ll a,b,c;
		cin >> a >> b >> c;
		ll z = (a * a) + (b * b) + (c * c);
		cout << z + 2 * min(a*b,min(b*c,a*c)) << "\n";
	}
}
