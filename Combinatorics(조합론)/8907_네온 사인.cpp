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
    int t;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        int N,sum=0;
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            for(int j=i+1;j<=N;j++)
            {
                int b;
                cin>>b;
                cnt[i]+=b,cnt[j]+=b;
            }
        }
        for(int i=1;i<=N;i++)
            sum+=cnt[i]*(N-1-cnt[i]);
        cout<<N*(N-1)*(N-2)/6-sum/2<<"\n";
    }
}
