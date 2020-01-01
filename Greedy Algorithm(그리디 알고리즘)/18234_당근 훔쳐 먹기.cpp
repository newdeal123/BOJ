#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
int N,T;
vector<pair<int,int>> v; //영양제,초기값

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll sum=0;

    cin>>N>>T;
    for(int i=0;i<N;i++)
    {
        int w,p;
        cin>>w>>p;
        v.push_back({p,w});
    }
    sort(v.rbegin(),v.rend());
    int cnt=T-1;
    for(int i=0;i<N&&-1<cnt;i++)
    {
        sum+=v[i].second+(ll)v[i].first*(cnt--);
    }
    cout<<sum;
}
