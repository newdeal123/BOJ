#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int H, W, lmax[500], rmax[500], ans = 0;
vector<int>v;

int main()
{
	cin>>H>>W;
	v.resize(W);
	for(auto&i:v)cin>>i;

	lmax[0] = v[0];
	rmax[W-1] = v[W-1];

	for(int i=1; i<W; i++)
    {
		lmax[i] = max(lmax[i-1], v[i]);
		rmax[W-1-i] = max(rmax[W-i], v[W-1-i]);
	}
	for(int i=0; i<W-2; i++)
		if(min(lmax[i+1],rmax[i+1])>=v[i+1])ans+=min(lmax[i+1],rmax[i+1])-v[i+1];
	cout<<ans;
}
