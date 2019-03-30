#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = (int)1E6;
vector <int> PrimeN;
int arr[MAX_N+1] = {0, };

void getPrimeN()
{
	for (int i = 2; i <= MAX_N; i++)
	{
		if (arr[i] == 0)
		{
			PrimeN.push_back(i);
			for (int j = i + i; j <= MAX_N; j += i)
				arr[j] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getPrimeN();

	int t;
	cin >> t;
	while (t--)
	{
		int n, sum = 0;
		cin >> n;
		for (int i = 0; i < PrimeN.size(); i++)
		{
			int p1 = PrimeN[i];
			int p2 = n - PrimeN[i];
			if (p1>n/2)
				break;
			if (arr[p2] == 0)
				sum++;
		}
		cout << sum << "\n";
	}

}