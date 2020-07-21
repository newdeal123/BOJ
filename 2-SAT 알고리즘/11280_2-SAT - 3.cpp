#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX_N=20000+2;
int N,M,cnt,scc,dfsN[MAX_N],sccN[MAX_N];
vector<int>adj[MAX_N];
bool finished[MAX_N];
stack<int>stk;

int DFS(int curr)
{
	dfsN[curr] = ++cnt;
	stk.push(curr);
	int ret = dfsN[curr];
	for(auto next: adj[curr])
    {
		if(dfsN[next] == 0) ret = min(ret, DFS(next));
		else if(!finished[next]) ret = min(ret, dfsN[next]);
	}
	if(ret >= dfsN[curr]){
		sccN[curr] = scc++;
		while(true)
        {
			int family = stk.top();
			stk.pop();
			finished[family] = true;
			if(family == curr) break;
			sccN[family] = sccN[curr];
		}
	}
	return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    while(M--)
    {
        int u,v;
        cin>>u>>v;
        u=(u>0?u*2-1:-2*(u+1));
        v=(v>0?v*2-1:-2*(v+1));
        adj[(u%2?u-1:u+1)].push_back(v); //!u->v
        adj[(v%2?v-1:v+1)].push_back(u); //!v->u
    }
    memset(finished,false,sizeof(finished));
    for(int i=0; i<N*2; i++)
		if(dfsN[i] == 0) DFS(i);

    for(int i=0; i<N; i++)
		if(sccN[i*2] == sccN[i*2+1]){
			cout<<false;
			return 0;
		}
    cout<<true;
}
