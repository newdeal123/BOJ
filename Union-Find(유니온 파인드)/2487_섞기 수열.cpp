#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a,int b)
{
    if(b==0)return a;
    return GCD(b,a%b);
}

int LCM(int a,int b)
{
    return a/GCD(a,b)*b;
}

int main()
{
    int N,ans=1;
    cin>>N;
    vector<int>v(N),visited(N,0);
    for(auto&i:v)cin>>i;

    for(int i=0;i<N;i++)
    {
        if(visited[i])continue;
        int cnt=1,now=v[i]-1;
        while(now!=i)
        {
            visited[now]=true;
            cnt++;
            now=v[now]-1;
        }
        ans=LCM(ans,cnt);
    }
    cout<<ans;

}
