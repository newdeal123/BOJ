#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int INF=987654321,MAX_N=1000+2;
int N,E,indegree[MAX_N]={0,},outdegree[MAX_N]={0,};
int adj[MAX_N][MAX_N]={0,};

bool checkEuler()
{
    int p=0,m=0;
    for(int i=0;i<N;i++)
    {
        int delta=outdegree[i]-indegree[i];
        if(abs(delta)>1)return false;
        if(delta==1)p++;
        if(delta==-1)m++;
    }
    return (p==0&&m==0);
}

void getEuler(int now,vector<int>&circuit)
{
    for(int next=0;next<N;next++)
    while(adj[now][next]>0)
    {
        adj[now][next]--;
        adj[next][now]--;
        getEuler(next,circuit);
    }
    circuit.push_back(now);
}

vector<int> getEuler()
{
    vector<int>circuit;
    for(int i=0;i<N;i++)
        if(outdegree[i])
    {
        getEuler(i,circuit);
        return circuit;
    }
    return circuit;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)
    {
           
        for(int j=0;j<N;j++)
        {
            cin>>adj[i][j];
            if(adj[i][j]){indegree[j]+=adj[i][j],outdegree[i]+=adj[i][j],E+=adj[i][j];}
        }
        if(outdegree[i]%2){cout<<-1;return 0;}
    }
    if(!checkEuler()){cout<<-1;return 0;}
    vector<int>ans=getEuler();
    reverse(ans.begin(),ans.end());
    if(ans.size()!=E/2+1){cout<<-1;return 0;}
    for(auto i:ans)cout<<i+1<<" ";
}


