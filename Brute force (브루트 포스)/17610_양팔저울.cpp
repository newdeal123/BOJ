#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int INF=987654321,MAX_N=13+2;
int N,arr[MAX_N],sum=0,bits=0,ans=0;
bool visited[MAX_N*200000]={0,};
int leftCache[(const int)pow(2,MAX_N)]={0,},rightCache[(const int)pow(2,MAX_N)]={0,};

int main()
{
    cin>>N;
    for(int i=0;i<N;i++){cin>>arr[i],sum+=arr[i];}

    for(int left=0;left<(1<<N);left++)
        for(int i=0;i<N;i++)if(left&(1<<i))leftCache[left]+=arr[i];
    for(int right=0;right<(1<<N);right++)
        for(int i=0;i<N;i++)if(right&(1<<i))rightCache[right]+=arr[i];

    for(int left=0;left<(1<<N);left++)
        for(int right=0;right<(1<<N);right++)
    {
        int tmp=leftCache[left]-rightCache[right];
        visited[abs(tmp)]=true;
    }
    for(int i=1;i<=sum;i++)if(!visited[i])ans++;
    cout<<ans;
}
