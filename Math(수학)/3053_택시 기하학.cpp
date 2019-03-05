#include<iostream>
#include<cmath>

#define PI 3.14159265358979323846
using namespace std;

int main()
{
	int x;
	cin >> x;
	cout << fixed;
	cout.precision(6);
	cout << x*x*PI << endl;
	cout << x*x * 2.0 << endl;
}
