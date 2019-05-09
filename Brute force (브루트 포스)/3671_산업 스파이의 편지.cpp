#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int arr[(int)1E7 + 1] = { 0, }; //prime:0 not prime:1
bool visited[(int)1E7 + 1] = { 0, };
int sum[10] = { 0, }, ans = 0;
string tmp;

void getPrime()
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < (int)1E7; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i + i; j < (int)1E7; j += i)
				arr[j] = 1;
		}
	}
}

void search(int n)
{
	if (arr[stoi(tmp)] == 0 && !visited[stoi(tmp)])
	{
		visited[stoi(tmp)] = true;
		ans++;
	}
	if (n < 0)
		return;

	for (int i = 0; i < 10; i++)
	{
		if (sum[i] > 0)
		{
			sum[i]--;
			tmp[n] = i + '0';
			search(n - 1);
			sum[i]++;
			tmp[n] = '0';
		}
	}
}

int main()
{
	int t;
	cin >> t;
	getPrime();
	while (t--)
	{
		string s;
		cin >> s;
		for (auto c : s)
		{
			sum[c - '0']++;
			tmp.push_back('0');
		}
		
		search(s.size() - 1);
		cout << ans << "\n";

		memset(sum, 0, sizeof(sum));
		memset(visited, 0, sizeof(visited));
		ans = 0;
		tmp.clear();
	}
}