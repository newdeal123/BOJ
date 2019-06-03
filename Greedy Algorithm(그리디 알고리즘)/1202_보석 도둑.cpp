#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int INF = 987654321;
struct Jewel
{
	int weight, value;
};

bool compare(Jewel &a, Jewel &b)
{
	return a.weight < b.weight;
}

int main()
{
	int N, K;
	long long sum = 0;
	cin >> N >> K;
	vector <Jewel> v;
	vector <int> bag;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < K; i++)
	{
		int tmp;
		cin >> tmp;
		bag.push_back(tmp);
	}
	sort(v.begin(), v.end(), compare);
	sort(bag.begin(), bag.end());
	priority_queue <int> pq;
	int cnt = 0;
	for (int i = 0;i< bag.size(); i++ )
	{
		int bag_size = bag[i];
		for (int j = cnt; j < v.size(); j++)
		{
			if (v[j].weight > bag_size)
				break;
			pq.push(v[j].value);
			cnt++;
		}
		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}