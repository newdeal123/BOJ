#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX_N=100+2;
int N,M,S,V,myHole[MAX_N],owner[MAX_N];
bool visited[MAX_N];
vector<pair<double,double>> mouse,hole;

bool canIn(int now,int thisHole)
{
    return (double)S*V >= (double)sqrt(pow(mouse[now].first-hole[thisHole].first,2)+
                               pow(mouse[now].second-hole[thisHole].second,2));
}

bool dfs(int now)
{
    if(visited[now]) return false;
    visited[now]=true;

    for(int thisHole=0;thisHole<M;thisHole++)
    {
        if(!canIn(now,thisHole)) continue;
        if(owner[thisHole]==-1 || dfs(owner[thisHole]))
        {
            myHole[now]=thisHole;
            owner[thisHole]=now;
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>N>>M>>S>>V;
    memset(myHole,-1,sizeof(myHole));
    memset(owner,-1,sizeof(owner));
    mouse.resize(N);
    hole.resize(M);
    for(int i=0;i<N;i++)
    {
        double x,y;
        cin>>x>>y;
        mouse[i]=make_pair(x,y);
    }
    for(int i=0;i<M;i++)
    {
        double x,y;
        cin>>x>>y;
        hole[i]=make_pair(x,y);
    }
    int sum=0;
    for(int i=0;i<N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(dfs(i)) sum++;
    }
    cout<<N-sum;

}
