#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll MAX_N = (ll)1E12;
int P, Q;
map <ll, ll> cache;

ll dp(int n)
{
	if (n == 0)
		return 1;
	
	if (cache[n])
		return cache[n];

	
	return cache[n] = dp(n / P) + dp(n / Q);

}

int main()
{
	int N;
	cin >> N >> P >> Q;
	cout << dp(N);
}