#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
const int MAX_N=10000+2;
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
        adj[u].push_back(v);
    }
    memset(finished,false,sizeof(finished));
    for(int i=1; i<=N; i++)
		if(dfsN[i] == 0) DFS(i);
    cout<<scc<<"\n";
    vector<int>v[scc];
    unordered_map<int,int>mp;
    int mpCnt=0;
    for(int i=1; i<=N; i++)
    {
        if(mp.find(sccN[i])==mp.end())
            mp.insert({sccN[i],mpCnt++});
        v[mp[sccN[i]]].push_back(i);
    }

    for(int i=0;i<scc;i++)
    {
        for(auto j:v[i])cout<<j<<" ";
        cout<<-1<<"\n";
    }
}
