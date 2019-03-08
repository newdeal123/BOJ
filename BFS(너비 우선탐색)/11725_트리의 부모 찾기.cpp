#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector <int> v;

void f(int n)
{
	cout << "f(" << n << ")\n";
	if (n > M)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;
		return;
	}

	for (int i = n; i <= N; i++)
	{
		v.push_back(i);
		f(n + 1);
		v.pop_back();
	}
	return;
}

int main()
{
	cin >> N >> M;
	f(1);
}