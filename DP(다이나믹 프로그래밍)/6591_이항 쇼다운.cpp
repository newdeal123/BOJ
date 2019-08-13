#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll cache[100001][21];

ll C(int n, int m)
{
    if(n==0) return 0;
	if (n==m || m==0) return 1;
	ll&ret = cache[n][m];
	if (ret!=-1) return ret;
	return ret=C(n-1,m)+C(n-1,m-1);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache,-1,sizeof(cache));
    while(true)
	{
	    int n, m;
        cin>>n>>m;
	    if(n==0&&m==0)return 0;
	    
        if(m>n/2)m=n-m;
        if(m==0)cout<<"1\n";
        else if(m==1)cout<<n<<"\n";
        else cout<<C(n, m)<<"\n";
	}
}
