#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
const int MAX_N=5000+2;
typedef long long ll;
int N,M,Q;

struct FENWICK
{
    ll tree[MAX_N][MAX_N];
    FENWICK();
    FENWICK(int y,int x){memset(tree,0,sizeof(tree));}
    void update(int y,int x,ll k)
    {
        for(int i=y;i<MAX_N+2;i+=i&-i)
            for(int j=x;j<MAX_N+2;j+=j&-j) tree[i][j]+=k;
    }
    ll query(int y,int x)
    {
        ll ret=0;
        for(int i=y;i>0;i-=i&-i)
            for(int j=x;j>0;j-=j&-j) ret+=tree[i][j];
        return ret;
    }

};

 int main()
 {
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cin>>N>>M>>Q;
     FENWICK fenwick(M,N);
     while(Q--)
     {
         int order;
         cin>>order;
         if(order==1)
         {
             int y[2],x[2],k;
             cin>>x[0]>>y[0]>>x[1]>>y[1]>>k;
             fenwick.update(x[1]+1,y[1]+1,k);
             fenwick.update(x[1]+1,y[0],-k);
             fenwick.update(x[0],y[1]+1,-k);
             fenwick.update(x[0],y[0],k);
         }
         else
         {
             int y,x;
             cin>>x>>y;
             cout<<fenwick.query(x,y)<<"\n";
         }
     }
 }
