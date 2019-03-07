//루트 없는 트리가 주어진다.이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 노드의 개수 N(2 ≤ N ≤ 100, 000)이 주어진다.둘째 줄부터 N - 1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.
//
//출력
//첫째 줄부터 N - 1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = (int)1E6;
vector <int> node[MAX_N];
int visited[MAX_N] = { 0, };
int NsParent[MAX_N];

void bfs()
{
	queue <int> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty())
	{
		int now_node = q.front();
		q.pop();
		for (int i = 0; i < node[now_node].size(); i++)
		{
			int ch_node = node[now_node][i];
			if (!visited[ch_node])
			{
				visited[ch_node] = 1;
				NsParent[ch_node] = now_node;
				q.push(ch_node);
			}
		}
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		node[tmp1].push_back(tmp2);
		node[tmp2].push_back(tmp1);
	}
	bfs();
	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", NsParent[i]);
	}
}