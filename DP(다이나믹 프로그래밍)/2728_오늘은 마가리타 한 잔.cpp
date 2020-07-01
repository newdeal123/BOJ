#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int V,D,cache[31][31][1001][2];
vector<int>cost;

//last:처음부터 연속된 구간의 마지막 값
int f(int idx,int last,int now,bool select)
{
    if(idx==V)return (select&&(last==idx||cost[last]>now));

    int&ret=cache[idx][last+1][now][select];
    if(ret!=-1)return ret;

    ret=f(idx+1,last,now,select);
    if(now>=cost[idx])
        ret+=f(idx+1,(idx==last?last+1:last),now-cost[idx],true);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(cache,-1,sizeof(cache));
        cin>>V>>D;
        cost.resize(V);
        for(auto&i:cost)cin>>i;

        sort(cost.begin(),cost.end());
        cout<<f(0,0,D,0)<<"\n";
    }
}
