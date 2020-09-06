#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAX_N=1000+2;
int cnt[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cnt,0,sizeof(cnt));
    int N,M,sum=0;
    cin>>N>>M;
    while(M--)
    {
        int a,b;
        cin>>a>>b;
        cnt[a]++,cnt[b]++;
    }
    for(int i=1;i<=N;i++)
        sum+=cnt[i]*(N-1-cnt[i]);
    cout<<N*(N-1)*(N-2)/6-sum/2<<"\n";

}
