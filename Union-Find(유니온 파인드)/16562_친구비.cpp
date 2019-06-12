#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=100000+2;
int N,M,K,cost[MAX_N];

struct UNION_FIND
{
    vector <int> parent,height,minCost;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),height.resize(n+1,1);
        minCost.resize(n+1);
        for(int i=1;i<=n;i++)
            {
                parent[i]=i;
                minCost[i]=cost[i];
            }
    }
    int find(int n)
    {
        if(parent[n]==n) return n;
        return find(parent[n]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v) return;
        if(height[u]>height[v])
            swap(u,v);
        parent[u]=v;
        minCost[v]=min(minCost[u],minCost[v]);
        if(height[u]==height[v])
            height[v]++;
    }
    int getCost(int n)
    {
        return minCost[find(n)];
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
        cin>>cost[i];
    UNION_FIND uf(N);
    while(M--)
    {
        int a,b;
        cin>>a>>b;
        uf.merge(a,b);
    }
    int sum=0;
    set <int> root;
    root.insert(uf.find(1));
    sum+=uf.getCost(1);
    for(int i=2;i<=N;i++)
    {
        int nowRoot=uf.find(i);
        if(root.find(nowRoot)!=root.end()) continue;
        sum+=uf.getCost(i);
        root.insert(nowRoot);
    }
    if(sum<=K) cout<<sum;
    else cout<<"Oh no";
}
