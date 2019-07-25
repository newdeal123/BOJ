#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int N, M;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
    cout << M - GCD(N, M);

}