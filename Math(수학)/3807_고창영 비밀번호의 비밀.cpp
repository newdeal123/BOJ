#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
int T, C;

ll f(ll a, ll p)
{
	ll r = 1;
	while (p) {
		if (p % 2) r *= a, r %= MOD;
		a *= a, a %= MOD, p /= 2;
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> C;
		ll ans = 1, n = 1;
		for (int i = 0; i < C; ++i)
		{
			ll P, A, val = 1;
			cin >> P >> A;
			ll PA = f(P, A);
			n *= PA, n %= MOD;
			PA *= A + 1, PA %= MOD;

			for (int j = 0; j < A; ++j)
				PA += val, PA %= MOD, val *= P, val %= MOD;
			ans *= PA, ans %= MOD;
		}
		ans += n, ans %= MOD;
		cout << ans << "\n";
	}
}