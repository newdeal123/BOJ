#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF=987654321;
bool connected[101];

int main()
{
    int N,K,cnt,ans=0;
    cin>>N>>K;
    cnt=N;
    queue<int>q[101];
    vector<int>v(K);
    for(int i=0;i<K;i++)
    {
        cin>>v[i];
        q[v[i]].push(i);
    }
    for(int i=1;i<=K;i++)q[i].push(INF);

    for(int i=0;i<K;i++)
    {
        if(cnt)
        {
            if(!connected[v[i]]) connected[v[i]]=true,cnt--;
            q[v[i]].pop();
        }
        else if(!connected[v[i]])
        {
            int maxN=0,target;
            for(int j=1;j<=K;j++)
                if(connected[j]&&maxN<q[j].front())
            {
                maxN=q[j].front();
                target=j;
            }
            connected[target]=false;
            connected[v[i]]=true;
            q[v[i]].pop();
            ans++;
        }
        else q[v[i]].pop();
        /*cout<<i+1<<": ";
        for(int i=1;i<=K;i++)cout<<connected[i]<<" ";
        cout<<endl;*/
    }
    cout<<ans;
}
