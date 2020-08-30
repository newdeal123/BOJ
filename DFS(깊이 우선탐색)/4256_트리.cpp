#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int>pre,in;

void dfs(int left,int right,int node)
{
    if(left>right) return ;
    for(int i=left;i<=right;i++)
        if(pre[node]==in[i])
    {
        dfs(left,i-1,node+1);
        dfs(i+1,right,node+i-left+1);
    }
    cout<<pre[node]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        pre.resize(N),in.resize(N);
        for(auto&i:pre)cin>>i;
        for(auto&i:in)cin>>i;
        dfs(0,N-1,0);
        cout<<"\n";
    }
}
