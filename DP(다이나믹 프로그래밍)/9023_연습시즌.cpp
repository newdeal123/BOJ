#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 100 + 2;
const int INF = 987654321;
int C, D, d;
int cache[MAX_N][MAX_N][2][2][MAX_N + MAX_N];
int Xn, Yn;
int arrX[MAX_N], arrY[MAX_N];

int f(int X_idx, int Y_idx, bool Xhotel, bool Yhotel, int days)
{

	if (X_idx == Xn && Y_idx == Yn)
		return 0;

	int& ret = cache[X_idx][Y_idx][Xhotel][Yhotel][days];
	if (ret != -1)
		return ret;
	ret = INF;

	if (X_idx == Xn)
	{
		if (Xhotel == false)
			return ret = min(ret, f(X_idx, Y_idx + 1, 1, 0, days + 1) + D + d + C);
		else
			return ret = min(ret, f(X_idx, Y_idx + 1, 1, 0, days + 1) + d + C);
	}
	if (Y_idx == Yn)
	{
		if (Yhotel == false)
			return ret = min(ret, f(X_idx + 1, Y_idx, 0, 1, days + 1) + D + d + C);
		else
			return ret = min(ret, f(X_idx + 1, Y_idx, 0, 1, days + 1) + d + C);
	}

	//둘다 훈련장에간다
	if (arrX[X_idx] == arrY[Y_idx])
		ret = min(ret, f(X_idx + 1, Y_idx + 1, 0, 0, days + 1) + C);
	else
		ret = min(ret, f(X_idx + 1, Y_idx + 1, 0, 0, days + 1) + C * 2);
	//한팀만 훈련장에간다
		if (Yhotel == false)
			ret = min(ret, f(X_idx + 1, Y_idx, 0, 1, days + 1) + D + d + C);
		else
			ret = min(ret, f(X_idx + 1, Y_idx, 0, 1, days + 1) + d + C);
	
		if (Xhotel == false)
			ret = min(ret, f(X_idx, Y_idx + 1, 1, 0, days + 1) + D + d + C);
		else
			ret = min(ret, f(X_idx, Y_idx + 1, 1, 0, days + 1) + d + C);
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> C >> D >> d;
		int cnt1 = 0, cnt2 = 0;
		while (true)
		{
			int tmp;
			cin >> tmp;
			if (!tmp)
				break;
			arrX[cnt1++] = tmp;
		}
		while (true)
		{
			int tmp;
			cin >> tmp;
			if (!tmp)
				break;
			arrY[cnt2++] = tmp;
		}
		Xn = cnt1, Yn = cnt2;
		cout << f(0, 0, 0, 0, 0) << "\n";
	}
}
