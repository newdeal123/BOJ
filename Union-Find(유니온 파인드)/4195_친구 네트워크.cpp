#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=100000+2;
int N,M;

struct UNION_FIND
{
    vector <int> parent,height,sum;
    UNION_FIND(){;};
    UNION_FIND(int n)
    {
        parent.resize(n+1),height.resize(n+1,1);
        sum.resize(n+1,1);
        for(int i=1;i<=n;i++)
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
        {
            cout<<sum[u]<<"\n";
            return;
        }
        if(height[u]>height[v])
            swap(u,v);
        parent[u]=v;
        sum[v]+=sum[u];
        if(height[u]==height[v])
            height[v]++;
        cout<<sum[v]<<"\n";
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N;
        UNION_FIND uf(N*2);
        unordered_map <string,int> mp;
        int cnt=1;
        while(N--)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
                mp.insert(make_pair(s1,cnt++));
            if(mp.find(s2)==mp.end())
                mp.insert(make_pair(s2,cnt++));
            uf.merge(mp[s1],mp[s2]);
        }

    }
}
