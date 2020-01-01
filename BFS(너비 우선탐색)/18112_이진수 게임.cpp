#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int d[2]={1,-1};

int two_to_ten(string s)
{
    int ret=0;
    for(int i=s.size()-1;i>=0;i--)
        ret+=(s[i]-'0')*(int)pow(2,s.size()-i-1);
    return ret;
}
int getLen(int n)
{
    if(n<2)return 1;
    return getLen(n/2)+1;
}

int bfs(int start,int fin)
{
    int visited[1<<10]={0,};
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        int now=q.front(),next;
        q.pop();
        if(now==fin)return visited[fin]-1;
        for(int i=0;i<2;i++)
        {
            next=now+d[i];
            if(visited[next]||next<0||next>=(1<<10))continue;
            visited[next]=visited[now]+1;
            q.push(next);
        }
        for(int i=0;i<getLen(now)-1;i++)
        {
            next=now^(1<<i);
            if(visited[next]||next<0||next>=(1<<10))continue;
            visited[next]=visited[now]+1;
            q.push(next);
        }
    }
    return -1;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<bfs(two_to_ten(s1),two_to_ten(s2));

}
