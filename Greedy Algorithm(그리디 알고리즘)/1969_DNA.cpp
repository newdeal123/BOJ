#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 987654321;

int main()
{
	int N, M;
	cin >> N >> M;
	vector <string> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	string ans;
	int HD = 0;
	for (int i = 0; i < M; i++)
	{
		int visited['Z' - 'A' + 1] = { 0, };
		for (int j = 0; j < N; j++)
			visited[v[j][i] - 'A']++;
		int maxN = 0, max_idx;
		for(int j=0;j<'Z'-'A'+1;j++)
			if (maxN < visited[j])
			{
				maxN = visited[j];
				max_idx = j;
			}
		ans.push_back(max_idx + 'A');
		HD += N - maxN;
	}
	for (auto c : ans)
		cout << c;
	cout << "\n" << HD;
}