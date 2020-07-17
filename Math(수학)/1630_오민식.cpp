#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD=987654321;


int main()
{
    int N;
    ll ans=1;
    cin>>N;
    bool visited[1000001];
    for(int i=2;i<=N;i*=2)
        ans=ans*2%MOD;
    for(int i=3;i<=N;i+=2)
    {
        if(visited[i])continue;
        for(ll j=i;j<=N;j*=i)
            ans=ans*i%MOD;
        for(ll j=(ll)i*i;j<=N;j+=i*2)
            visited[j]=true;
    }
    cout<<ans%MOD;
}
