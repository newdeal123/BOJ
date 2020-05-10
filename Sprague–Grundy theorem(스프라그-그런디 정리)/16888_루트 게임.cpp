#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <bitset>
using namespace std;
const int MAX_N=(int)1e6+2;
int N;
bool cache[MAX_N],visited[MAX_N];
vector<int>v;

bool f(int now)
{
    if(now==0)return 0;

    if(visited[now])return cache[now];
    visited[now]=true;
    bool&ret=cache[now];
    ret=0;
    for(auto i:v)
    {
        if(i>now)break;
        ret=ret ||!f(now-i);
    }
    return ret;
}

void getV()
{
    for(int i=1;(long long)i*i<MAX_N;i++)
        v.push_back(i*i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    getV();
    memset(visited,0,sizeof(visited));
    memset(cache,0,sizeof(cache));
    while(t--)
    {
        cin>>N;
        if(f(N))cout<<"koosaga\n";
        else cout<<"cubelover\n";
    }

}
