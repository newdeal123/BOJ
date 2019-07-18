#include <bits/stdc++.h>
using namespace std;
const int MAX_N=300+2;
int N,M,K,T;
int people[MAX_N],cache[MAX_N][MAX_N][MAX_N];

int f(int time,int plusP,int P)
{
    if(time==N+1) return 0;

    int&ret=cache[time][plusP][P];
    if(ret!=-1)return ret;
    ret=0;

    if(people[time]>=T) return ret=f(time+1,0,P)+1;
    else if(people[time]+plusP>=T) return ret=f(time+1,plusP,P)+1;
    for(int i=0;i<=P;i++)
        ret=max(ret,f(time+1,plusP+i,P-i)+(people[time]+plusP+i>=T));
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N>>M>>K>>T;
    for(int i=0;i<M;i++)
    {
        int start,fin;
        cin>>start>>fin;
        for(int j=start;j<fin;j++)
            people[j]++;
    }
    cout <<f(1,0,K);
}
