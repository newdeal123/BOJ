//재서기는 수혀니와 교외 농장에서 숨바꼭질을 하고 있다.농장에는 헛간이 많이 널려있고 재석이는 그 중에 하나에 숨어야 한다.
//헛간의 개수는 N(2 <= N <= 20, 000)개이며, 1 부터 샌다고 하자.
//
//재서기는 수혀니가 1번 헛간부터 찾을 것을 알고 있다.모든 헛간은 M(1 <= M <= 50, 000)개의 양방향 길로 이어져 있고, 
//그 양 끝을 A_i 와 B_i(1 <= A_i <= N; 1 <= B_i <= N; A_i != B_i)로 나타낸다.
//또한 어떤 헛간에서 다른 헛간으로는 언제나 도달 가능하다고 생각해도 좋다.
//
//재서기는 발냄새가 지독하기 때문에 최대한 냄새가 안나게 숨을 장소를 찾고자 한다.
//냄새는 1번 헛간에서의 거리(여기서 거리라 함은 지나야 하는 길의 최소 개수이다)가 멀어질수록 감소한다고 한다.
//재서기의 발냄새를 최대한 숨길 수 있는 헛간을 찾을 수 있게 도와주자!
//
//입력
//첫 번째 줄에는 N과 M이 공백을 사이에 두고 주어진다.
//
//이후 M줄에 걸쳐서 A_i와 B_i가 공백을 사이에 두고 주어진다.
//
//
//
//출력
//출력은 한줄로 이루어지며, 세 개의 값을 공백으로 구분지어 출력해야한다.
//
//첫 번째는 숨어야 하는 헛간 번호를(만약 거리가 같은 헛간이 여러개면 가장 작은 헛간 번호를 출력한다), 
//두 번째는 그 헛간까지의 거리를, 세 번째는 그 헛간과 같은 거리를 갖는 헛간의 개수를 출력해야한다.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 20000 + 2;
const int INF = 987654321;
int N, M;
vector <int> node[MAX_N];

void dijkstra()
{
	vector <int> dist(N+1, INF);
	priority_queue <pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > dist[now])
			continue;
		for (int i = 0; i < node[now].size(); i++)
		{
			int next = node[now][i];
			int nextDist = cost + 1;
			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
		vector <int> ans;
		int maxDist = 0;
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == maxDist)
				ans.push_back(i);
			else if (dist[i] > maxDist)
			{
				ans.clear();
				ans.push_back(i);
				maxDist = dist[i];
			}
		}
		cout << ans[0] << " " << maxDist << " " << ans.size();
	
}

int main()
{
	cin >> N >> M;
	while (M--)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		node[tmp1].push_back(tmp2);
		node[tmp2].push_back(tmp1);
	}
	dijkstra();
}
