#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAX_N=2000002;
int N,cache[MAX_N][2],arr[MAX_N];
vector<int>adj[MAX_N];

int f(int idx,bool mustSkip)
{
    if(adj[idx].size()==0)
    {
        if(mustSkip)return 0;
        else return max(0,arr[idx]);
    }
    int&ret=cache[idx][mustSkip];
    if(ret!=-1)return ret;
    ret=0;

    int sum=0;
    for(auto next:adj[idx])
        sum+=f(next,0);

    ret=max(ret,sum);
    if(!mustSkip)
    {
        int sum=arr[idx];
        for(auto next:adj[idx])
            sum+=f(next,1);
        ret=max(ret,sum);
    }
    return ret;

}

void output(bool boss,int idx,bool mustSkip)
{
    if(adj[idx].empty())
    {
        if(!mustSkip&&arr[idx]>0)cout<<idx<<" ";
        return ;
    }
    if(idx==1)
    {
        if(boss)
        {
            cout<<idx<<" ";
            for(auto next:adj[idx])
                if(f(next,1)>0)output(boss,next,1);
        }
        else
        {
            for(auto next:adj[idx])
                if(f(next,0)>0)output(boss,next,0);
        }
    }
    else
    {
        if(mustSkip)
        {
            for(auto next:adj[idx])output(boss,next,0);
            return ;
        }
        int sum1=0,sum2=arr[idx];
        vector<int>v1,v2;
        for(auto next:adj[idx])
                {
                    if(f(next,0)>0)
                    {
                        sum1+=f(next,0);
                        v1.push_back(next);
                    }
                    if(!mustSkip&&f(next,1)>0)
                    {
                        sum2+=f(next,1);
                        v2.push_back(next);
                    }
                }
        if(sum1>sum2)
        {
            for(auto next:v1)output(boss,next,0);
        }
        else
        {
            cout<<idx<<" ";
            for(auto next:v2) output(boss,next,1);
        }


    }

    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=1;i<=N;i++)cin>>arr[i];
    for(int i=2;i<=N;i++)
    {
        int v;
        cin>>v;
        adj[v].push_back(i);
    }
    int sum1=0,sum2=arr[1];
    for(auto next:adj[1])sum1+=f(next,0);
    for(auto next:adj[1])sum2+=f(next,1);
    cout<<sum2<<" "<<sum1<<"\n";
    output(1,1,0);
    cout<<"-1\n";
    output(0,1,0);
    cout<<"-1";
}
