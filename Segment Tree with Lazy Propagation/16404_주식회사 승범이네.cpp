#include <bits/stdc++.h>
using namespace std;
const int MAX_N=100000+2;
int N,M,s[MAX_N],e[MAX_N],order=-1;
vector<int> adj[MAX_N];

void dfs(int now)
{
    s[now]=++order;
    for(auto next:adj[now]) dfs(next);
    e[now]=order;
    return ;
}

struct SEG_TREE
{
    int n;
    vector <int> tree,lazy;
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
        return update(left,right,value,1,0,n-1);
    }
    void update(const int left,const int right,const int value,int node,int nodeLeft,int nodeRight)
    {
        propagate(node,nodeLeft,nodeRight);
        if(nodeRight<left || right<nodeLeft) return;
        if(left<=nodeLeft && nodeRight<=right)
        {
            lazy[node]+=value;
            return;
        }
        int mid=(nodeLeft+nodeRight)/2;
        update(left,right,value,node*2,nodeLeft,mid);
        update(left,right,value,node*2+1,mid+1,nodeRight);
        tree[node]=tree[node*2]+tree[node*2+1];
    }

    int output(int left,int right)
    {
        return output(left,right,1,0,n-1);
    }
    int output(const int left,const int right,int node,int nodeLeft,int nodeRight)
    {
        propagate(node,nodeLeft,nodeRight);
        if(nodeRight<left || right<nodeLeft) return 0;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;

        return output(left,right,node*2,nodeLeft,mid)+output(left,right,node*2+1,mid+1,nodeRight);
    }

};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    int tmp;
    cin>>tmp;
    for(int i=2;i<=N;i++)
    {
        cin>>tmp;
        adj[tmp].push_back(i);
    }
    SEG_TREE seg(N);
    dfs(1);
    while(M--)
    {
        int order,i,w;
        cin>>order;
        if(order==1)
        {
            cin>>i>>w;
            seg.update(s[i],e[i],w);
        }
        else
        {
            cin>>i;
            cout<<seg.output(s[i],s[i])<<"\n";
        }
    }

}
