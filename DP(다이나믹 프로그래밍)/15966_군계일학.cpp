#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
const int MAX_N=(int)1e6+2;
int N,cache[MAX_N],ans=0;
vector<int>v;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    for(auto&i:v)
    {
        cin>>i;
        cache[i]=max(cache[i],cache[i-1]+1);
        ans=max(ans,cache[i]);
    }
    cout<<ans;
}
