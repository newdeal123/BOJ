#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map<string,int> cache;
int N,M, aMatch[1001],bMatch[1001];
vector<vector<int>>fav;
bool visited[1001];

bool dfs(int u)
{
    if(visited[u])return false;
    visited[u]=true;
    for(auto v:fav[u])
    {
        if(bMatch[v]==-1 || dfs(bMatch[v]))
        {
            bMatch[v]=u;
            aMatch[u]=v;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    int keys=1;
    for(int i=0;i<M;i++)
    {
        string s;
        cin>>s;
        cache.insert({s,keys++});
    }
    fav.resize(N);
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        while(n--)
        {
            string s;
            cin>>s;
            fav[i].push_back(cache[s]);
        }
    }

    memset(aMatch,-1,sizeof(aMatch));
    memset(bMatch,-1,sizeof(bMatch));
    int sum=0;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(dfs(i))sum++;
    }
    if(sum==N)cout<<"YES";
    else cout<<"NO"<<endl<<sum;
}
