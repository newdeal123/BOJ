#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int cache[10000+4],C,N,M;
ll ans[10000+4];
vector<pair<int,int>>gift;

int main()
{
    cin>>C>>N>>M;
    for(int i=0;i<N;i++)
    {
        int s,p;
        cin>>s>>p;
        gift.push_back({s,p});
    }
    memset(cache,-1,sizeof(cache));
    cache[0]=0;

    for(int i=0;i<N;i++)
        for(int j=C;j>=1;j--)
        if(j>=gift[i].first)
            cache[j]=max(cache[j],cache[j-gift[i].first]+gift[i].second);

    for(int cost=1;cost<=C;cost++)
        for(int i=1;i<=M&&i*cost<=C;i++)
            ans[i]=max(ans[i],(ll)i*cache[cost]);
            
    for(int i=1;i<=M;i++)cout<<ans[i]<<"\n";
}
