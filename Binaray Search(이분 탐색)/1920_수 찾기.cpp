#include  <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, M;
vector <int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	while (M--)
	{
		int targetN;
		bool success = false;
		cin >> targetN;
		int left = 0, right = v.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (v[mid] == targetN)
			{
				success = true;
				break;
			}
			else if (v[mid] >= targetN)
				right = mid - 1;
			else if (v[mid] <= targetN)
				left = mid + 1;
		}
		if (success) cout << "1\n";
		else cout << "0\n";
	}
}