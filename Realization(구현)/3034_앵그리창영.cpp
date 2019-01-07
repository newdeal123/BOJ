//성냥이 박스에 들어가려면, 박스의 밑면에 성냥이 모두 닿아야 한다.
//
//박스의 크기와 성냥의 길이가 주어졌을 때, 성냥이 박스에 들어갈 수 있는지 없는지를 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 던진 성냥의 개수 N과 박스의 크기 W와 H가 주어진다. (1 ≤ N ≤ 50, 1 ≤ W, H ≤ 100)
//
//다음 N개 줄에는 성냥의 길이가 주어진다.길이는 1보다 크거나 같고 1000보다 작거나 같은 자연수이다.
//
//출력
//입력으로 주어지는 각각의 성냥에 대해서, 박스안에 들어갈 수 있으면 "DA" 없으면 "NE"를 출력한다.

#include <iostream>
using namespace std;

//피타고라스정리이용
int Pythagorean(int w, int h)
{
	int n = w*w + h*h;
	int n_r = 1;
	for (int i = 1; i < n; i++)
	{
		if (i*i > n)
		{
			n_r = i - 1;
			break;
		}
	}

	return n_r;
}

int main()
{
	int n, w, h, n_r;
	cin >> n >> w >> h;
	n_r = Pythagorean(w, h);
	for (int i = 0; i < n; i++)
	{
		int match;
		cin >> match;
		if (match <= n_r)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;

	}
}