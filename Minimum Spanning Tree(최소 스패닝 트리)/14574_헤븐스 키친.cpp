#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=987654321;
const int MAX_N=1000+2;
int N;
bool visited[MAX_N]={0,};
vector<pair<int,int>>v;
vector<int>ans[MAX_N];

struct UNION_FIND
{
    vector <int> parent,height;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),height.resize(n+1,1);
        for(int i=0;i<n;i++)
                parent[i]=i;

    }
    int find(int n)
    {
        if(parent[n]==n) return n;
        return find(parent[n]);
    }
    void merge(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v)
            return;
        if(height[u]>height[v])
            swap(u,v);
        parent[u]=v;
        if(height[u]==height[v])
            height[v]++;
    }
};

int getScore(int i,int j)
{
    return (double)(v[i].second+v[j].second)/(double)abs(v[i].first-v[j].first);
}
ll kruskal()
{
    ll ret=0;
    vector <pair<int,pair<int,int>>> edges;
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            edges.push_back(make_pair(getScore(i,j),make_pair(i,j)));
    sort(edges.rbegin(),edges.rend());
    UNION_FIND uf(N);
    for(auto i:edges)
    {
        int cost=i.first,u=i.second.first,v=i.second.second;
        if(uf.find(u)==uf.find(v)) continue;
        uf.merge(u,v);
        ans[u].push_back(v);
        ans[v].push_back(u);
        ret+=(ll)cost;
    }
    return ret;
}

void dfs(int u)
{
    visited[u]=true;
    for(auto v:ans[u])
        if(!visited[v])
    {
        dfs(v);
        cout<<u+1<<" "<<v+1<<"\n";
    }

}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i]=make_pair(a,b);
    }
    cout<<kruskal()<<endl;
    dfs(0);

}
