// 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
// 입력
// 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

// 출력
// 첫째 줄에 연결 요소의 개수를 출력한다.

#include <stdio.h>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int str[1005][1005];
int n, m;
int point;
int vis[1005];
void d(int a)
{
	vis[a] = 1;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i] && str[a][i]) {
			d(i);
		}
	}
}
  
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; ++i) 
	{
		int x, y;
		scanf("%d %d", &x, &y);
		str[x][y] = 1;
		str[y][x] = 1;
	}
	for (int i = 1; i <= n; ++i) 
	{
		if (!vis[i]) 
		{
			++point;
			d(i);
		}
	}
	printf("%d",point);
}