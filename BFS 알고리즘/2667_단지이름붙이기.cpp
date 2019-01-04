// 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
// 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
// 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다.
// <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 
// 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

// 출력
// 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

#include <stdio.h>
#include <queue> 
#include <vector>
#include <algorithm>

#pragma warning (disable: 4996)

using namespace std;

int main(void) {
	int n;
	int map[30][30];
	int visit[30][30];
	int count = 0;
	queue<int> row;
	queue<int> col;
	int rt;
	int ct;
	vector<int> cnt;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
			visit[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				row.push(i);
				col.push(j);
				visit[i][j] = 1;
				count++;
				cnt.push_back(0);
				cnt[count-1]++;
			}

			while (!row.empty()) {
				rt = row.front();
				ct = col.front();

				row.pop();
				col.pop();

				if (map[rt + 1][ct] == 1 && visit[rt + 1][ct] == 0) {
					row.push(rt + 1);
					col.push(ct);
					visit[rt + 1][ct] = 1;
					cnt[count - 1]++;
				}
				
				if (map[rt - 1][ct] == 1 && visit[rt - 1][ct] == 0) {
					row.push(rt - 1);
					col.push(ct);
					visit[rt - 1][ct] = 1;
					cnt[count - 1]++;
				}
				
				if (map[rt][ct + 1] == 1 && visit[rt][ct + 1] == 0) {
					row.push(rt);
					col.push(ct + 1);
					visit[rt][ct + 1] = 1;
					cnt[count - 1]++;
				}
				
				if (map[rt][ct - 1] == 1 && visit[rt][ct - 1] == 0) {
					row.push(rt);
					col.push(ct - 1);
					visit[rt][ct - 1] = 1;
					cnt[count - 1]++;
				}
			}
		}
	}

	sort(cnt.begin(), cnt.end());

	printf("%d\n", cnt.size());
	for (int i = 0; i < cnt.size(); i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}