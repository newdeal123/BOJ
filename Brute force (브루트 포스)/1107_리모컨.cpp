#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;
bool breakdown[10] = { 0, };
string channel;
int minN = INF, N, targetN;

void f(int n)
{
	if (n != 0)
		minN = min(minN, abs(targetN - stoi(channel.substr(0, n))) + n);

	if (n > N)
		return;

	for (int i = 0; i < 10; i++)
	{
		if (!breakdown[i])
		{
			channel[n] = i + '0';
			f(n + 1);
		}
	}

}

int main()
{
	cin >> targetN;
	N = to_string(targetN).size();
	channel.resize(N + 1);
	int i;
	cin >> i;
	while (i--)
	{
		int tmp;
		cin >> tmp;
		breakdown[tmp] = true;
	}
	f(0);
	int minN_cpy = minN;
	for (int i = minN_cpy; i >= 0; i--)
	{
		if (100 + i == targetN || 100 - i == targetN)
			minN = i;
	}
	cout << minN;
}