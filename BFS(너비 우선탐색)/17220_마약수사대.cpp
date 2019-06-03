#include <bits/stdc++.h>
using namespace std;
const int MAX_N=30;
int N,M,state[MAX_N]={0,};
vector <int> node[MAX_N];

int bfs(vector<int> v, int st)
{
    queue <int> q;
    for(int i=0;i<v.size();i++)
    {
        if(state[v[i]]) continue;
        state[v[i]]=st;
        q.push(v[i]);
    }

    while(!q.empty())
    {
        int now=q.front();
        q.pop();

        for(int i=0;i<node[now].size();i++)
        {
            int next=node[now][i];
            if(!state[next])
            {
                q.push(next);
                state[next]=st;
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >>N >> M;
    vector <int> arrest,rt;
    bool visited[MAX_N]={0,};
    while(M--)
    {
        char c1,c2;
        cin >>c1>>c2;
        node[c1-'A'].push_back(c2-'A');
        visited[c2-'A']=true;
    }
   int t;
   cin >> t;
   while(t--)
   {
       char c;
       cin>>c;
       arrest.push_back(c-'A');
       state[c-'A']=1;
   }

   for(int i=0;i<N;i++)
    if(!visited[i])
    rt.push_back(i);

   bfs(rt,2);

   int cnt=0,sub=0;
    for(int i=0;i<N;i++)
        if(state[i]==2)
        cnt++;

    for(int i=0;i<rt.size();i++)
        if(state[rt[i]]==2)
            sub++;
    cout <<cnt-sub;
}
