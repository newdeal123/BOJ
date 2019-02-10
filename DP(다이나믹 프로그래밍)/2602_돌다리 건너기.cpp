//절대반지를 얻기 위하여 반지원정대가 출발한다.원정대가 지나가야할 다리는 두 개의 인접한 돌다리로 구성되어 있다.
//하나는 <악마의 돌다리>이고 다른 하나는 <천사의 돌다리>이다.
//
//아래 그림 1은 길이가 6인 다리의 한 가지 모습을 보여준다.그림에서 위의 가로줄은 <악마의 돌다리>를 표시하는 것이고, 
//아래의 가로줄은 <천사의 돌다리>를 표시한다.두 돌다리의 길이는 항상 동일하며, 
//각 칸의 문자는 해당 돌에 새겨진 문자를 나타낸다.두 다리에 새겨진 각 문자는{ R, I, N, G, S } 중 하나이다.
//
//출발	R	I	N	G	S	R	도착
//		G	R	G	G	N	S
//
//
//반지원정대가 소유하고 있는 마법의 두루마리에 <악마의 돌다리>와 <천사의 돌다리>를 건너갈 때 반드시 순서대로 밟고 지나가야할 문자들이 적혀있다.
//이 순서대로 지나가지 않으면 돌다리는 무너져 반지원정대는 화산 속으로 떨어지게 된다.
//
//다리를 건널 때 다음의 제한 조건을 모두 만족하면서 건너야 한다.
//
//1) 왼쪽(출발지역)에서 오른쪽(도착지역)으로 다리를 지나가야 하며, 반드시 마법의 두루마리에 적힌 문자열의 순서대로 모두 밟고 지나가야 한다.
//
//2) 반드시 <악마의 돌다리>와 <천사의 돌다리>를 번갈아가면서 돌을 밟아야 한다.단, 출발은 어떤 돌다리에서 시작해도 된다.
//
//3) 반드시 한 칸 이상 오른쪽으로 전진해야하며, 건너뛰는 칸의 수에는 상관이 없다.
//
//마법의 두루마리에 적힌 문자열과 두 다리의 돌에 새겨진 문자열이 주어졌을 때, 돌다리를 통과할 수 있는 모든 가능한 방법의 수를 계산하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에는 마법의 두루마리에 적힌 문자열(R, I, N, G, S 로만 구성된)이 주어진다.이 문자열의 길이는 최소 1, 최대 20 이다.
//그 다음 줄에는 각각 <악마의 돌다리>와 <천사의 돌다리>를 나타내는 같은 길이의 문자열이 주어진다.그 길이는 1 이상, 100 이하이다.
//
//출력
//마법의 두루마리에 적힌 문자열의 순서대로 다리를 건너갈 수 있는 방법의 수를 출력한다.그러한 방법이 없으면 0을 출력한다.
//
//모든 테스트 데이터에 대한 출력결과는 231 - 1 이하이다.
#include <iostream>
#include <string>
using namespace std;

#define MAX_N 105
int map[3][MAX_N];
int target[21];
int targetstring_len;
int mapstring_len;
int cache[3][MAX_N][21];

int bridge(int y, int x, int target_num)
{
	//기저사례1 :  target의길이를 모두 충족했을때
	if (target_num == targetstring_len + 1)
	{
		//test
		/*cout << "bridge(" << y << "," << x << "," << target_num << ")\n";*/
		return 1;
	}

	int& ret = cache[y][x][target_num];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = x + 1; i <= mapstring_len; i++)
	{
		if (y == 1)
		{
			if (map[2][i] == target[target_num])
				ret += bridge(2, i, target_num + 1);
		}
		else if (y == 2)
		{
			if (map[1][i] == target[target_num])
				ret += bridge(1, i, target_num + 1);
		}
	}

	return ret;
}

int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < MAX_N; j++)
			for (int k = 0; k < 21; k++)
				cache[i][j][k] = -1;

	string target_s;
	cin >> target_s;
	for (int i = 0; i < (signed)target_s.size(); i++)
		target[i+1] = target_s[i];
	targetstring_len = target_s.size();

	string s;
	cin >> s;
	for (int i = 0; i <(signed)s.size(); i++)
		map[1][i+1] = s[i];
	string s2;
	cin >> s2;
	for (int i = 0; i < (signed)s2.size(); i++)
		map[2][i+1] = s2[i];
	mapstring_len = s.size();

	//test
	/*for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= mapstring_len; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}*/

	cout << bridge(1, 0, 1) + bridge(2, 0, 1);

}