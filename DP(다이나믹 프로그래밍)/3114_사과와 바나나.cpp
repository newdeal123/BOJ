#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 1500;
int N, M;
//누적합보다 메모리가 2배 더소요됨 다음에 재풀이할때는 누적합 방식을 사용할것..
int cache[MAX_N + 1][MAX_N + 1];
int cacheY[MAX_N + 1][MAX_N + 1];
int cacheX[MAX_N + 1][MAX_N + 1];

//string 2차원 배열로 선언
string arr[MAX_N + 1][MAX_N + 1];
int goY[3] = { 1,1,0 };
int goX[3] = { 1,0,1 };

bool isinmap(int y, int x)
{
	if (y<1 || y>N || x<1 || x>M)
		return false;
	return true;
}

//state방향으로 불도저가 지나갔을때, 확정된y줄에있는 모든 사과나무들 합계에넣는다.
//for문 그냥 돌리면 시간초과가 나므로 dp내의dp선언(...)
//처음엔 3차원 cache를 사용했으나 생각해보니 state는 변하지않으므로 2차원만 사용해도 되겠더라
int plusY(int y, int x, int state)
{
	if (y > N)
		return 0;
	if (state == 1)
		return 0;

	int& ret = cacheY[y][x];
	if (ret != -1)
		return ret;
	if (arr[y + 1][x][0] == 'A' && y+1 <= N)
		return ret = plusY(y + 1, x, state) + stoi(arr[y + 1][x].substr(1));
	else
		return ret = plusY(y + 1, x, state);
}

//plusY함수의 주석과 동일하다.
int plusX(int y, int x, int state)
{
	if (x > M)
		return 0;
	if (state == 2)
		return 0;

	int& ret = cacheX[y][x];
	if (ret != -1)
		return ret;
	if (arr[y][x + 1][0] == 'B' && x+1 <=M)
		return ret = plusX(y, x + 1, state) + stoi(arr[y][x + 1].substr(1));
	else
		return ret = plusX(y, x + 1, state);
}

//main DP함수. 현재좌표를 값으로갖고 도착점 도착하면 끝.
int go(int y, int x)
{
	if (y == N && x == M)
		return 0;
	int& ret = cache[y][x];
	if (ret != -1)
	{
		return ret;
	}

	for (int i = 0; i < 3; i++)
	{
		int nextY = y + goY[i], nextX = x + goX[i];
		if (isinmap(nextY, nextX))
		{
			ret = max(ret, go(nextY, nextX) + plusY(y, x, i) + plusX(y, x, i));
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//1시간 넘어서야 찾아낸 *틀렸습니다*의 원인.. sizeof( )<-안에 들어갈 변수명을 모두 cache로 선언하는 바람에
	//근데왜 예제랑 초반테케 몇개를 통과한걸까
	//덕분에 int형 long long 형으로 바꾸는 등의 뻘짓을했다.,,
	memset(cache, -1, sizeof(cache));
	memset(cacheY, -1, sizeof(cacheY));
	memset(cacheX, -1, sizeof(cacheX));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	cout << go(1, 1);
}