#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Quest
{
	int str, intel, pnt;
};
int cache[1002][1002];
bool visited[1002] = { 0, };
vector <Quest> quest;
int N;

int f(int nowS, int nowI)
{
	int &ret = cache[nowS][nowI];
	if (ret != -1)
		return ret;

	ret = 0;
	int point = 0; 
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		if (quest[i].str <= nowS || quest[i].intel <= nowI)
		{
			if (!visited[i])
			{
				visited[i] = true;
				v.push_back(i);
				point += quest[i].pnt;
			}
			ret++;
		}

	}

	for (int i = 0; i <= point; i++)
	{
		int nextS = nowS + i > 1000 ? 1000 : nowS + i;
		int nextI = nowI + point - i > 1000 ? 1000 : nowI + point - i;
		ret = max(ret, f(nextS, nextI));
	}

	for (int i = 0; i < v.size(); i++)
		visited[v[i]] = false;

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	quest.resize(N);
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		quest[i] = { a,b,c };
	}
	cout << f(1, 1);
}

