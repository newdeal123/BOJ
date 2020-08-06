#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int cache[201][201],N;
vector<int>know;

int f(int idx,int last)
{
    if(idx==N)return 1;
    int&ret=cache[idx][last];
    if(ret!=-1)return ret%MOD;
    ret=0;
    for(int i=last;i<=know[idx];i++)
        ret=((ll)ret+(ll)f(idx+1,i))%MOD;
    return ret%MOD;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(cache,-1,sizeof(cache));
        cin>>N;
        know.resize(N);
        for(auto&i:know)cin>>i;
        sort(know.begin(),know.end());
        cout<<((ll)f(0,1)*N)%MOD<<"\n";

    }
}
