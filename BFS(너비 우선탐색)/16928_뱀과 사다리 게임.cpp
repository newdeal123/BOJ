#include <bits/stdc++.h>
using namespace std;
int N,M;
int jump[101]={0,},visited[101]={0,};

int BFS()
{
    queue<int>q;
    visited[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=1;i<=6;i++)
        {
            int next=now+i;
            if(jump[next]!=0)next=jump[next];
            if(next>100||visited[next])continue;
            visited[next]=visited[now]+1;
            q.push(next);
        }
    }
    return visited[100]-1;
}

int main()
{
    cin>>N>>M;
    int t=N+M;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        jump[a]=b;
    }
    cout<<BFS();
}
