#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;
const int MAX_N=100000+2;
vector<int>adj[MAX_N],sccId,discoverd;
stack<int>stk;
int sccCnt,vertexCnt,V,E;

int scc(int here)
{
    int ret=discoverd[here]=vertexCnt++;
    stk.push(here);
    for(auto next:adj[here])
    {
        if(discoverd[next]==-1)ret=min(ret,scc(next));
        else if(sccId[next]==-1) ret=min(ret,discoverd[next]);
    }
    if(ret==discoverd[here])
    {
        vector<int>nowScc;
        while(true)
        {
            int tmp=stk.top();
            stk.pop();
            sccId[tmp]=sccCnt;
            if(tmp==here)break;
        }
        sccCnt+=1;
    }
    return ret;
}

vector<int> tarjanSCC()
{
    sccId=discoverd=vector<int>(MAX_N,-1);
    sccCnt=vertexCnt=0;
    for(int i=1;i<=V;i++)if(discoverd[i]==-1)scc(i);
    return sccId;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>V>>E;
        for(int i=0;i<MAX_N;i++)adj[i].clear();
        while(E--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        vector<int>ans=tarjanSCC();
        int indegree[MAX_N]={0,};
        for(int i=1;i<=V;i++)
            for(auto j:adj[i])
                if(ans[i]!=ans[j])indegree[ans[j]]++;
        int cnt=0;
        for(int i=0;i<sccCnt;i++) if(indegree[i]==0)cnt++;
        cout<<cnt<<"\n";
    }
}
