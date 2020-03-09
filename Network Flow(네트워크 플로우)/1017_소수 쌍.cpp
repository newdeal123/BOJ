#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_N=100+2;
int N,M,aMatch[MAX_N],bMatch[MAX_N];
bool visited[MAX_N],isPrime[2000+2];
vector<int>adj[MAX_N];

bool dfs(int now)
{
    if(visited[now]||now==0) return false;
    visited[now]=true;
    for(auto next:adj[now])
    {
        if(bMatch[next]==-1 || dfs(bMatch[next]))
        {
            bMatch[next]=now;
            aMatch[now]=next;
            return true;
        }
    }
    return false;
}

void getPrime()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    for(int i=2;i<=sqrt(2000+2);i++)
    {
        if(!isPrime[i])continue;
        for(int j=i+i;j<2000+2;j+=i) isPrime[j]=false;
    }
}


int main()
{
    getPrime();
    cin>>N;
    vector<int>A,B,ans;
    int tmp;
    cin>>tmp;
    A.push_back(tmp);
    for(int i=1;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp%2==A.front()%2)A.push_back(tmp);
        else B.push_back(tmp);
    }
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)if(isPrime[A[i]+B[j]])adj[i].push_back(j);
    for(auto j:adj[0])
    {
        memset(aMatch,-1,sizeof(aMatch));
        memset(bMatch,-1,sizeof(bMatch));
        int cnt=1;
        bMatch[j]=0;
        aMatch[0]=j;
        for(int i=1;i<A.size();i++)
        {
            memset(visited,0,sizeof(visited));
            if(dfs(i))cnt++;
        }
        //for(int i=0;i<N/2;i++)cout<<aMatch[i]<<" ";
        //cout<<endl;
        if(cnt==N/2)ans.push_back(B[j]);
    }
    sort(ans.begin(),ans.end());
    if(ans.empty())cout<<"-1";
    else for(auto i:ans)cout<<i<<" ";

}
