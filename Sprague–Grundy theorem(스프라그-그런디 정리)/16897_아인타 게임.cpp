#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=100+2;
int N,M,K,cache[MAX_N][MAX_N];
int goY[3]={0,1,0},goX[3]={1,0,0};

int f(int nowY,int nowX)
{
    if(nowY==N&&nowX==M)return 0;
    int&ret=cache[nowY][nowX];
    if(ret!=-1)return ret;

    bool visited[101]={0,};
    for(int i=0;i<3;i++)
    {
        int nextY=nowY+goY[i],nextX=nowX+goX[i];
        if(nextY<1||nextY>N||nextX<1||nextX>M)continue;
        visited[f(nextY,nextX)]=true;
    }
    for(int i=0;i<101;i++)if(!visited[i]) return ret= i;
}

int db(int k,int y,int x)
{
    if((y%(k+1)==0 && x>=y) || (x%(k+1)==0 && y>=x)) return ((y+x)%2!=0)+2;
    else if(k==1 || (min(y,x)/(k+1))%2==0) return ((y+x)%2!=0);
    else return ((y+x)%2==0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>K>>N>>M;
        cout<<(db(K,N,M)>0?"koosaga":"cubelover")<<"\n";
    }
}
