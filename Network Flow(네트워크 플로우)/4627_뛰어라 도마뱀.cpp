#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=400+2,MAX_V=MAX_N*2+2,INF=987654321;
int N,M,D,S=MAX_N-2,E=MAX_N-1,capacity[MAX_V][MAX_V],flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int in(int num){return num*2;}
int out(int num){return num*2+1;}
int networkFlow(int source,int sink)
{
    memset(flow,0,sizeof(flow));
    int totalSum=0;
    while(true)
    {
        vector <int> parent(MAX_V,-1);
        queue <int> q;
        parent[source]=source;
        q.push(source);
        while(!q.empty()&&parent[sink]==-1)
        {
            int now=q.front();q.pop();
            for(auto next:adj[now])
            {
                if(capacity[now][next]-flow[now][next]>0 && parent[next]==-1)
                {
                    q.push(next);
                    parent[next]=now;
                }
            }
        }
        if(parent[sink]==-1) break;
        int sum=INF;
        for(int p=sink;p!=source;p=parent[p])
            sum=min(capacity[parent[p]][p]-flow[parent[p]][p],sum);
        for(int p=sink;p!=source;p=parent[p])
        {
            flow[parent[p]][p]+=sum;
            flow[p][parent[p]]-=sum;
        }
        totalSum+=sum;
    }
    return totalSum;
}

void connect(int u,int v,int cap)
{
    capacity[u][v]=cap;
    capacity[v][u]=cap;
    adj[v].push_back(u);
    adj[u].push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,testCase=1;
    cin>>t;
    while(t--)
    {
        cin>>N>>D;
        memset(capacity,0,sizeof(capacity));
        memset(flow,0,sizeof(flow));
        for(int i=0;i<MAX_V;i++)adj[i].clear();

        for(int i=0;i<N;i++)
        {
            string s;
            cin>>s;
            M=s.size();
            for(int j=0;j<M;j++)
            {
                int num=i*M+j;
                connect(out(num),in(num),s[j]-'0');
                //capacity[in(num)][out(num)]-=s[j]-'0';
            }
        }
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                for(int i2=0;i2<N;i2++)
                    for(int j2=0;j2<M;j2++)
                        if(abs(i-i2)+abs(j-j2)<=D)
        {
            int u=i*M+j,v=i2*M+j2;
            if(u==v)continue;
            connect(out(u),in(v),INF);
            capacity[in(v)][out(u)]-=INF;
        }

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(i<D||N-i<=D||j<D||M-j<=D)
                    {
                        int num=i*M+j;
                        connect(out(num),in(E),INF);
                        capacity[in(E)][out(num)]-=INF;
                    }
        int lizard=0;
        for(int i=0;i<N;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<M;j++)
                if(s[j]=='L')
                {
                    int num=i*M+j;
                    connect(out(S),in(num),1);
                    capacity[in(num)][out(S)]-=1;
                    lizard++;
                }
        }
        int lasts=lizard-networkFlow(out(S),in(E));
        cout<<"Case #"<<testCase++<<": ";
        if(lasts==0)cout<<"no lizard was left behind.\n";
        else if(lasts==1)cout<<lasts<<" lizard was left behind.\n";
        else cout<<lasts<<" lizards were left behind.\n";
    }
}
