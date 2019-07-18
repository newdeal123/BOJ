#include <bits/stdc++.h>
using namespace std;
const int MAX_N=10000+2,MAX_P=1000+2;
int cache[MAX_N][MAX_P],N;
string s;
vector <pair<int,char>> node[MAX_N];

int f(int now,int idx)
{
    if(idx==s.size()) return 1;

    int&ret=cache[now][idx];
    if(ret !=-1) return ret;
    ret=0;
    for(auto i:node[now])
    {
        int next=i.first,flower=i.second;
        if(flower==s[idx])
            ret+=f(next,idx+1);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        node[a].push_back(make_pair(b,c));
    }
    cin>>s;
    long long sum=0;
    for(int i=1;i<=N;i++)
        sum+=f(i,0);
    cout<<sum;
}
