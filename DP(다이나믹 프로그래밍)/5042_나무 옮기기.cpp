#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;
int N,L,W;
const double INF=INT_MAX-100.0;
double cache[2000][2000];
vector<int>v;
vector<double>toSeed;

double f(int leftIdx,int rightIdx)
{
    int idx=leftIdx+rightIdx;
    if(idx==N)return 0.0;

    double&ret=cache[leftIdx][rightIdx];
    if(ret>-0.5)return ret;
    ret=INF;
    if(leftIdx!=N/2)
        ret=min(ret,f(leftIdx+1,rightIdx)+abs(toSeed[leftIdx]-(double)v[idx]));

    if(rightIdx!=N/2)
        ret=min(ret,f(leftIdx,rightIdx+1)+sqrt(pow(abs(toSeed[rightIdx]-(double)v[idx]),2)+(double)W*W));

    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>L>>W;
    v.resize(N);
    toSeed.resize(N/2);
    for(auto&i:v)cin>>i;
    sort(v.begin(),v.end());

    toSeed[0]=0.0;
    for(int i=1;i<N/2;i++)toSeed[i]=toSeed[i-1]+(double)L/(N/2-1);
    
    cout<<fixed;
    cout.precision(7);
    cout<<f(0,0);
}
