#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <deque>
using namespace std;
#include <vector>
typedef long long ll;
const ll INF=(ll)1<<60;
const int MAX_N=100000+2;
int N,D;
vector<int>v;
ll DP[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>D;
    v.resize(N);
    for(auto&i:v)cin>>i;
    for(int i=0;i<N;i++)DP[i]=-INF;
    deque<int>dq;

    for(int i=0;i<N;i++)
    {
        while(!dq.empty())
        {
            if(abs(i-dq.front())>D)dq.pop_front();
            else break;
        }
        if(dq.empty())DP[i]=0;
        else DP[i]=max((ll)0,DP[dq.front()]);
        DP[i]+=v[i];

        while(!dq.empty())
        {
            if(DP[dq.back()]<=DP[i])dq.pop_back();
            else break;
        }
        dq.push_back(i);
    }
    ll ret=-INF;
    for(int i=0;i<N;i++)ret=max(ret,DP[i]);
    cout<<ret;
}
