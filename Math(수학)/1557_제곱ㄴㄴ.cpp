#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_PRIME = 100000;
const int MAX_RES = 2000000000l;

void SieveOfEratosthenes(vector<ll> &a)
{
	bool prime[MAX_PRIME + 1];
	memset(prime, true, sizeof(prime));

	for (ll p = 2; p*p <= MAX_PRIME; p++)
	{
		if (prime[p] == true)
		{
			for (ll i = p * 2; i <= MAX_PRIME; i += p)
				prime[i] = false;
		}
	}

	for (ll p = 2; p <= MAX_PRIME; p++)
		if (prime[p])
			a.push_back(p);
}

ll countSquares(ll i, ll cur,ll k, vector<ll> &a)
{
	ll square = a[i] * a[i];
	ll newCur = square*cur;
	if (newCur > k)
		return 0;
	ll cnt = k / (newCur);
	cnt += countSquares(i + 1, cur, k, a);
	cnt -= countSquares(i + 1, newCur, k, a);

	return cnt;
}

ll f(ll n)
{
	vector <ll> a;
	SieveOfEratosthenes(a);
	ll low = 1;
	ll high = MAX_RES;

	while (low < high)
	{
		ll mid = low + (high - low) / 2;
		ll c = mid - countSquares(0, 1, mid, a);
		if (c < n)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}
int main()
{
	int N;
	cin >> N;
	cout << f(N);
}