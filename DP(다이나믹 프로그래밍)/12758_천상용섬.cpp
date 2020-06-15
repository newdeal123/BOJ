#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
//(1~1e6) 까지의 수의 약수의 개수의 최대값:240
int N,cache[301][241];
vector<int>tree,adj[301];


int f(int idx,int last)
{
    if(idx==N)return 1;

    int&ret=cache[idx][last];
    if(ret!=-1)return ret%MOD;
    ret=0;
    int lastN=(idx==0?0:adj[idx-1][last]);
    for(int i=0;i<adj[idx].size();i++)
        if(adj[idx][i]>=lastN)ret=((ll)ret+f(idx+1,i))%MOD;

    return ret%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N;
        memset(cache,-1,sizeof(cache));
        tree.resize(N);
        for(auto&i:tree)cin>>i;
        for(int i=0;i<N;i++)
        {
            adj[i].clear();
            for(int j=1;j<=sqrt(tree[i]);j++)
                if(tree[i]%j==0)
            {
                int downN=j,upN=tree[i]/j;
                adj[i].push_back(downN);
                if(downN==upN)continue;
                adj[i].push_back(upN);
            }
            sort(adj[i].begin(),adj[i].end());
        }
        cout<<f(0,0)<<"\n";
    }
}
