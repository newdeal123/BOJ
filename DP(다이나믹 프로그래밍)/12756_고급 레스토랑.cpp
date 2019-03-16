#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int A_at, B_at;

//win A:1, win B:2, draw:0;
int Play_HS(int A_hp, int B_hp)
{
	if (A_hp <= 0)
	{
		if (B_hp <= 0)
			return 0;
		else
			return 2;
	}
	if(B_hp <= 0)
	{
		if (A_hp <= 0)
			return 0;
		else
			return 1;
	}

	return Play_HS(A_hp - B_at, B_hp - A_at);
}

int main()
{
	int A_hp, B_hp;
	cin >> A_at >> A_hp >> B_at >> B_hp;
	switch (Play_HS(A_hp,B_hp))
	{
	case 0:
		cout << "DRAW";
		break;
	case 1:
		cout << "PLAYER A";
		break;
	case 2:
		cout << "PLAYER B";
		break;
	}
}