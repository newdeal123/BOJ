// N×M크기의 배열로 표현되는 미로가 있다.미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
// 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
// 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
// 입력
// 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

// 출력
// 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

#include <stdio.h>
#include <queue>

using namespace std;

int map[110][110];
int visit[110][110];

int main(void) {
	int n, m;
	int turn = 0;
	
	queue<int> row;
	queue<int> col;

	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	row.push(1);
	col.push(1);
	visit[1][1] = 1;

	while (!visit[n][m]) {
		int size = row.size();


		for (int i = 1; i <= size; i++) {
			int now_row = row.front();
			int now_col = col.front();
			row.pop();
			col.pop();

			//오른쪽
			if (map[now_row][now_col + 1] == 1 && visit[now_row][now_col + 1] == 0) {
				row.push(now_row);
				col.push(now_col + 1);
				visit[now_row][now_col + 1] = 1;
			}
			//왼쪽
			if (map[now_row][now_col - 1] == 1 && visit[now_row][now_col - 1] == 0) {
				row.push(now_row);
				col.push(now_col - 1);
				visit[now_row][now_col - 1] = 1;
			}

			//위쪽
			if (map[now_row-1][now_col] == 1 && visit[now_row-1][now_col] == 0) {
				row.push(now_row-1);
				col.push(now_col);
				visit[now_row-1][now_col] = 1;
			}

			//아래쪽
			if (map[now_row+1][now_col] == 1 && visit[now_row+1][now_col] == 0) {
				row.push(now_row+1);
				col.push(now_col);
				visit[now_row+1][now_col] = 1;
			}
		}
        
		turn++;
	}

	printf("%d\n", turn+1);

	return 0;
}
