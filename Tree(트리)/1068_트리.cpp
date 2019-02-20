//트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.
//
//트리가 주어졌을 때, 노드 중 하나를 제거할 것이다.그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 트리의 노드의 개수 N이 주어진다.N은 50보다 작거나 같은 자연수이다.
//둘째 줄에는 0번 노드부터 N - 1번 노드까지, 각 노드의 부모가 주어진다.만약 부모가 없다면(루트) - 1이 주어진다.셋째 줄에는 지울 노드의 번호가 주어진다.
//
//출력
//첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.
#include <iostream>
#include <vector>
#define MAX_N 50+2
using namespace std;

int eraseN;
vector <pair<int, bool>> node[MAX_N];

//없앨 부모노드를 인자로받아 bfs로 탐색하면서 bool값을 false로만든다.
void make_false(int parent)
{
	for (int i = 0; i < (signed)node[parent].size(); i++)
	{
		node[parent][i].second = false;
		make_false(node[parent][i].first);
	}

	return;
}

//리프노드를 찾아서 갯수를 반환
int findleaf(int root)
{
	if (node[root].size() == 0)
		return 1;

	int ret = 0;
	for (int i = 0; i < (signed) node[root].size(); i++)
	{
		if (node[root][i].second == true && node[root][i].first != eraseN)
			ret += findleaf(node[root][i].first);
	}

	return ret;
}

int main()
{
	int n, root;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		if (parent == -1)
			root = i;
		node[parent].push_back(make_pair(i, true));
	}

	cin >> eraseN;
	make_false(eraseN);
	
	if (root == eraseN)
	{
		cout << "0";
		return 0;
	}
	if (findleaf(root) == 0)
	{
		cout << "1";
		return 0;
	}
	else
		cout << findleaf(root);

}