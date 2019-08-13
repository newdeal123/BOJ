#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=987654321;
int N,cache[1000000+1][2];

int getMax(int n)
{
    string s=to_string(n);
    int maxN=-INF;
    for(auto c:s)maxN=max(maxN,c-'0');
    return maxN;
}
int getMin(int n)
{
    string s=to_string(n);
    int minN=INF;
    for(auto c:s)if(c!='0')minN=min(minN,c-'0');
    return minN;
}

int f(int n,bool myturn)
{
    if(n<10 && myturn)return true;
    if(n<10 && !myturn)return false;

    int&ret=cache[n][myturn];
    if(ret!=-1)return ret;
    int maxN=getMax(n),minN=getMin(n);
    if(myturn) return ret=max(f(n-maxN,!myturn),f(n-minN,!myturn));
    else return ret=min(f(n-maxN,!myturn),f(n-minN,!myturn));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cache,-1,sizeof(cache));
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N;
        if(f(N,1))cout<<"YES\n";
        else cout<<"NO\n";
    }

}
