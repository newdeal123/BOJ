#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;
vector<vector<int>> adj;
vector<int>sccId,discoverd;
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
    sccId=discoverd=vector<int>(adj.size(),-1);
    sccCnt=vertexCnt=0;
    for(int i=0;i<adj.size();i++)if(discoverd[i]==-1)scc(i);
    return sccId;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>V>>E;
    adj.resize(V+1);
    while(E--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>ans=tarjanSCC();
    cout<<sccCnt-1<<"\n";
    bool visited[10000+2]={0,},flag=true;
    for(int i=1;i<ans.size();i++)
    {
        if(!visited[ans[i]])
        {
            int target=ans[i];
            for(int i=1;i<ans.size();i++)
                if(target==ans[i])cout<<i<<" ";
            cout<<"-1\n";
            visited[ans[i]]=true;
        }
    }
}
