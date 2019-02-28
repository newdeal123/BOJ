//1부터 N까지 정수 N개로 이루어진 순열을 나타내는 방법은 여러 가지가 있다.
//
//순열을 배열을 이용해  로 나타냈다면, i에서 πi로 간선을 이어 그래프로 만들 수 있다.
//
//N개의 정수로 이루어진 순열이 주어졌을 때, 순열 사이클의 개수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 테스트 케이스의 개수 T가 주어진다.각 테스트 케이스의 첫째 줄에는 순열의 크기 N(2 ≤ N ≤ 1, 000)이 주어진다.
//둘째 줄에는 순열이 주어지며, 각 정수는 공백으로 구분되어 있다.
//
//출력
//각 테스트 케이스마다, 입력으로 주어진 순열에 존재하는 순열 사이클의 개수를 출력한다.
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> node[1000 + 2];
int visited[1000 + 2] = { 0, };
int cycleSum = 0;

void Set()
{
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 1002; i++)
		node[i].clear();
	cycleSum = 0;
}

void bfs(int startN, int idx)
{
	//cout << "bfs(" << startN << "," << idx << ")\n";
	visited[idx] = 1;
	for (int i = 0; i < node[idx].size(); i++)
	{
		if (node[idx][i] == startN)
		{
			cycleSum++;
			return;
		}
		else 
		{
			visited[node[idx][i]] = 1;
			bfs(startN, node[idx][i]);
		}
	}
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			node[i].push_back(tmp);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				visited[i] = 1;
				bfs(i, i);
			}
		}

		cout << cycleSum << endl;

		Set();
	}
}