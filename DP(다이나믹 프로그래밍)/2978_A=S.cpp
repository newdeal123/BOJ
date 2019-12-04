#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int arr[1001], N, cache[1001][5001], skipTo[1001] = { 0, };
string ans;

int f(int idx, int sum)
{
	if (idx == N)
	{
		if (sum == 0)return 0;
		else return INF;
	}
	if (idx != N - 1 && arr[idx] == 0)return f(skipTo[idx], sum);

	int&ret = cache[idx][sum];
	if (ret != -1)return ret;
	ret = INF;
	for (int len = 1; idx + len <= N; len++)
	{
		string tmp;
		for (int i = 0; i<len; i++)tmp.push_back(arr[idx + i] + '0');
		if (sum - stoi(tmp) < 0)break;
		ret = min(ret, f(idx + len, sum - stoi(tmp)) + 1);
	}
	return ret;

}

void output(int idx, int sum)
{
	if (idx == N) return;

	int minN = INF, minLen, minSum;
	for (int len = 1; idx + len <= N; len++)
	{
		string tmp;
		for (int i = 0; i<len; i++)tmp.push_back(arr[idx + i] + '0');
		if (sum - stoi(tmp) < 0)break;
		if (minN > f(idx + len, sum - stoi(tmp)) + 1)
		{
			minN = f(idx + len, sum - stoi(tmp)) + 1;
			minLen = len;
			minSum = stoi(tmp);
		}
	}

	for (int i = idx; i < idx + minLen; i++)ans.push_back(arr[i] + '0');
	ans.push_back('+');
	return output(idx + minLen, sum - minSum);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int sum;
	string s;
	cin >> s;
	for (int i = 0; i<s.size(); i++)
	{
		if (s[i] == '=')
		{ 
			N = i; sum = stoi(s.substr(i + 1)); 
			int idx = i - 1;
			for (int j = i - 1; j >= 0; j--)
			{
				if (s[j] == '0') skipTo[j] = idx;
				else idx = j;
			}
			break; 
		}
		arr[i] = s[i] - '0';
	}
	/*for (int i = 0; i < N; i++)cout << skipTo[i]<<" ";
	cout << endl;*/
	output(0, sum);

	for (int i = 0; i<ans.size() - 1; i++)cout << ans[i];
	cout << "=" << sum;
}
