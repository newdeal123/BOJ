#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX_N 10000+5
#define ll long long
using namespace std;
int n,price[MAX_N],cache[MAX_N][2];
vector<int> adj[MAX_N],tree[MAX_N];
bool visited[MAX_N]={0,};

void dfs(int now)
{
    visited[now]=true;
    for(auto next:adj[now])
        if(!visited[next])
    {
        dfs(next);
        tree[now].push_back(next);
    }
}

int f(int node,bool isGood)
{
    int&ret=cache[node][isGood];
    if(ret!=-1)return ret;
    ret=(isGood?price[node]:0);
    for(auto next:tree[node])
        {
            int tmp=0;
            if(isGood)tmp=max(tmp,f(next,false));
            else tmp=max(tmp,max(f(next,false),f(next,true)));
            ret+=tmp;
        }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> price[i];
    for(int i=0;i<n-1;i++)
    {
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	cout<<max(f(1,true),f(1,false));

}
