#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX_N = 200 + 2;
int N, ability[MAX_N][15]; // i번이닝에서의 j번선수의 능력치

void baseMove(int base[], int n)
{
	for (int i = 3; i >= 1; i--)
	{
		if (i - n < 1)	base[i] = 0;
		else	base[i] = base[i - n];
	}
	if (n != 4)	base[n] = 1;
}


int getScore(vector <int>& v)
{
	int nowIdx = 0, score = 0;
	for (int inning = 1; inning <= N; inning++)
	{
		int base[4] = { 0, }, outCount = 0;
		while (outCount < 3)
		{
			int ab = ability[inning][v[nowIdx]];
			if (!ab)
				outCount++;
			else
			{
				int sum = 0;
				if (ab== 4) sum++;
				for (int i = 3; ab > 0 && i > 0; i--, ab--)
					if (base[i]) sum++;
				score += sum;
				ab = ability[inning][v[nowIdx]];
				for (int i = 3; i >= 1; i--)
				{
					if (i - ab < 1)	base[i] = 0;
					else	base[i] = base[i - ab];
				}
			if (ab != 4)	base[ab] = 1;
		}
			nowIdx = nowIdx == 8 ? 0 : nowIdx + 1;
		}
	}
	return score;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++)
			cin >> ability[i][j];
	vector <int> v;
	for (int j = 2; j <= 9; j++)
		v.push_back(j);

	int maxN = 0;
	do
	{
		vector <int> tmp = v;
		vector <int> ::iterator it;
		it = tmp.begin() + 3;
		tmp.insert(it, 1);
		maxN = max(maxN, getScore(tmp));
	} while (next_permutation(v.begin(), v.end()));

	cout << maxN;
}