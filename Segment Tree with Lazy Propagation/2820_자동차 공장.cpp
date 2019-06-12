#include <bits/stdc++.h>
using namespace std;
const int MAX_N=500000+2;
int N,M;
typedef long long ll;
vector <int> adj[MAX_N];
int cost[MAX_N],s[MAX_N],e[MAX_N],order=-1;

void dfs(int now)
{
    s[now]=++order;
    for(auto next:adj[now])
        if(s[next]==-1) dfs(next);
    e[now]=order;
}

struct SEG_TREE
{
    int n;
    vector<ll>lazy,tree;
    SEG_TREE(){;};
    SEG_TREE(int s)
    {
        n=s;
        tree.resize(n*4,0),lazy.resize(n*4,0);
    }
    void propagate(int node,int nodeLeft,int nodeRight)
    {
        if(lazy[node])
        {
            if(nodeLeft!=nodeRight)
            {
                lazy[node*2]+=lazy[node];
                lazy[node*2+1]+=lazy[node];
            }
        tree[node]+=lazy[node]*(nodeRight-nodeLeft+1);
        lazy[node]=0;
        }
    }
    void update(int left,int right,int value)
    {
        return update(1,value,left,right,0,n-1);
    }
    void update(int node,int value,const int left,const int right,int nodeLeft,int nodeRight)
    {
        propagate(node,nodeLeft,nodeRight);
        if(nodeRight<left || nodeLeft>right) return ;
        if(left<=nodeLeft && nodeRight<=right)
        {
            lazy[node]+=value;
            //propagate(node,nodeLeft,nodeRight);
            return ;
        }
        int mid=(nodeLeft+nodeRight)/2;
        update(node*2,value,left,right,nodeLeft,mid);
        update(node*2+1,value,left,right,mid+1,nodeRight);
       // tree[node]=tree[node*2]+tree[node*2+1];
    }
    ll query(int left,int right)
    {
        return query(1,left,right,0,n-1);
    }
    ll query(int node,int left,int right,int nodeLeft,int nodeRight)
    {
        propagate(node,nodeLeft,nodeRight);
        if(nodeRight<left || nodeLeft>right) return 0;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(node*2,left,right,nodeLeft,mid)+query(node*2+1,left,right,mid+1,nodeRight);
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(s,-1,sizeof(s));
    cin>>N>>M;
    SEG_TREE seg(N);
    cin>>cost[0];
    for(int i=1;i<N;i++)
    {
        int tmp;
        cin>>cost[i]>>tmp;
        adj[tmp-1].push_back(i);
    }
    dfs(0);
    for(int i=0;i<N;i++)
        seg.update(s[i],s[i],cost[i]);
    for(int i=0;i<M;i++)
    {
        char c;
        int a,x;
        cin>>c;
        if(c=='p')
        {
            cin>>a>>x;
            a-=1;
            seg.update(s[a]+1,e[a],x);
        }
        else
        {
            cin>>a;
            a-=1;
            cout<<seg.query(s[a],s[a])<<"\n";
        }
    }

    return 0;
}
