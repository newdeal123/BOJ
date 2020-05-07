#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N=(int)1e5+2;
int G,P;
vector<int>v;

struct UNION_FIND
{
    int n;
public:
    vector<int>parent,height,Sum;
    UNION_FIND(){;}
    UNION_FIND(int s)
    {
        n=s+1;
        parent.resize(n),height.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int u)
    {
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>G>>P;
    v.resize(P);
    for(auto&i:v)cin>>i;
    UNION_FIND uf(G);
    int cnt=0;
    for(auto i:v)
    {
        int tmp=uf.find(i);
        if(tmp==0)break;
        uf.parent[tmp]=tmp-1;
        cnt++;
    }
    cout<<cnt;

}
