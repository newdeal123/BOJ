#include <bits/stdc++.h>
using namespace std;
vector <int> node[22];
int visited[22]={0,},n;

void dfs(int now)
{
    visited[now]=true;
    for(auto next:node[now])
        if(!visited[next])
            dfs(next);
}

int dfsAll()
{
    int cnt=0;
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            {
                dfs(i);
                cnt++;
            }
    }
    return cnt;
}

int main()
{
    int turn=1;
    while(true)
    {
        for(int i=0;i<22;i++)
            node[i].clear();
        int cnt=1;
        cin >>n;
        if(!n) break;
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
                mp.insert(make_pair(s1,cnt++));
            if(mp.find(s2)==mp.end())
                mp.insert(make_pair(s2,cnt++));
            node[mp[s1]].push_back(mp[s2]);
            node[mp[s2]].push_back(mp[s1]);
        }
        cout << turn++ <<" " <<dfsAll() <<"\n";
    }
}
