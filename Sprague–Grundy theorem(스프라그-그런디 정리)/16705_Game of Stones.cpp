#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N=1000000+2;
int n,a,b;
int arr[MAX_N];

string ans()
{
	int minN = min(a,b);
	int k = 0,bigger = 0,lastBigN = 0;

	for(int i=0;i<n;i++)
	{
		k ^= (arr[i] % (minN+1));
		if (arr[i] > minN )
		{
			lastBigN = arr[i];
			bigger++;
		}
	}

	if (bigger == 0 || a == b)
	{
		if (k) return "Petyr";
		else return "Varys";
	}
	else if (bigger == 1 && minN == a)
    {
		int tmp = k ^ (lastBigN % (a + 1));
		int d = (((lastBigN - tmp) % (a + 1))+a+1) % (a+1);
		if (d <= 0 || d > a || lastBigN - d > a) return "Varys";
		if (tmp != (lastBigN - d) % (a + 1)) return "Varys";
		return "Petyr";
	}
	else
    {
		if (a < b) return "Varys";
		else return "Petyr";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> a >> b;

	for(int i=0;i<n;i++)
        cin >> arr[i];
    cout<<ans();
}

