#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll  N, time = 0, sum = 0, tmp_sum = 0;
	cin >> N;
	priority_queue <ll> pq;
	for (int i = 0; i < N*N; i++)
	{
		ll tmp;
		cin >> tmp;
		pq.push(-tmp);
		sum += tmp;
	}
	while (true)
	{
		if ((long double)sum*0.5 <= (long double)tmp_sum)
			break;
		time++;
		while (-pq.top() < time)
			pq.pop();
		tmp_sum += pq.size();
	}
	cout << time;
}