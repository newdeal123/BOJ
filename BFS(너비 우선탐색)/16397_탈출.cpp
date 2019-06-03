#include <bits/stdc++.h>
using namespace std;
const int MAX_N=99999;
const int INF=987654321;
int N,T,G,cache[MAX_N+2];

int B(int n)
{
    string s=to_string(n*2);
    s[0]-=1;
    return stoi(s);
}

int BFS()
{
    int visited[MAX_N]={0, };
    queue <int> q;
    visited[N]=1;
    q.push(N);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        int next=now+1;
        if(!visited[next] && next<=MAX_N)
        {
            visited[next]=visited[now]+1;
            q.push(next);
        }
        if(!now || now*2> MAX_N) continue;
        next=B(now);
        if(!visited[next] && next<=MAX_N)
        {
            visited[next]=visited[now]+1;
            q.push(next);
        }
    }

    return visited[G]==0 ? INF : visited[G]-1;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin >> N>>T>>G;
    int ret= BFS();
    if(ret>T) cout << "ANG";
    else cout << ret;
}
