#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N,M,aMatch[102],bMatch[102];
vector<int>arr[102];
bool visited[102];

bool dfs(int u)
{
    if(visited[u])return false;
    visited[u]=true;
    for(auto v:arr[u])
        if(bMatch[v]==-1||dfs(bMatch[v]))
    {
        bMatch[v]=u;
        aMatch[u]=v;
        return true;
    }
    return false;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>M;
        for(int i=0;i<102;i++)arr[i].clear();
        memset(aMatch,-1,sizeof(aMatch));
        memset(bMatch,-1,sizeof(bMatch));
        for(int i=0;i<M;i++)
        {
            int t1,t2,a;
            cin>>t1>>t2>>a;
            while(a--)
            {
                int q;
                cin>>q;
                for(int j=t1;j<t2;j++)arr[j].push_back(q);
            }
        }
        int cnt=0,time=0;
        for(time=0;time<102;time++)
        {
            if(cnt==N)break;
            memset(visited,0,sizeof(visited));
            if(dfs(time))cnt++;
        }
        if(cnt==N)cout<<time<<"\n";
        else cout<<-1<<"\n";
    }
}
