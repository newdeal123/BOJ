#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF=987654321;
int D,N,cache[102],pSum[102]={0,},time[102];
vector<int>ans;


 int f(int idx)
 {
     if(pSum[N+1]-pSum[idx]<=D) return 0;

     int&ret=cache[idx];
     if(ret!=-1) return ret;
     ret=INF;
     for(int i=idx+1;i<=N;++i)
         if(pSum[i]-pSum[idx]<=D)ret=min(ret,f(i)+time[i-1]);
     return ret;
 }

 void output(int idx)
 {
     if(pSum[N+1]-pSum[idx]<=D) return ;
     int minN=INF,target;

     for(int i=idx+1;i<=N;++i)
         if(pSum[i]-pSum[idx]<=D && minN>=f(i)+time[i-1])
         {
             minN=f(i)+time[i-1];
             target=i;
         }
     ans.push_back(target);
     return output(target);
 }

 int main()
 {
     memset(cache,-1,sizeof(cache));
     cin>>D>>N;
     for(int i=0;i<=N;i++)
     {
         int tmp;
         cin>>tmp;
         pSum[i+1]=pSum[i]+tmp;
     }
     for(int i=0;i<N;i++)cin>>time[i];
     cout<<f(0)<<"\n";
     output(0);
     cout<<ans.size()<<"\n";
     for(auto i:ans)cout<<i<<" ";
 }
