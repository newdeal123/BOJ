#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int alpN='z'-'a'+1;
int N,ans=0;
vector<string>v;
vector<ll>mybit;

void dfs(int idx,ll bits,ll allBits)
{
    if(idx==N)
    {
        if(bits==(1<<alpN)-1)ans++;
        return ;
    }
    dfs(idx+1,bits,allBits);
    dfs(idx+1,bits|mybit[idx],allBits|(1<<idx));
    return ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(auto&s:v)
    {
        cin>>s;
        ll bit=0;
        for(auto c:s)
            bit|=(1<<(c-'a'));
        mybit.push_back(bit);
    }
    dfs(0,0,0);
    cout<<ans;
}
