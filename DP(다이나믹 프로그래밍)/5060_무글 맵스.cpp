#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=987654321;
int N,C;
double cache[201][201],Sum[201][201];
vector<int>arr;

double Lin_Inter(int i,int j,int k)
{
    return (double)arr[i]+(double)(arr[j]-arr[i])*(double)(k-i)/(double)(j-i);
}

double ABS(double d)
{
    if(d>0.0)return d;
    else return -d;
}

void getSum()
{
    for(int i=0;i<N;i++)
        for(int j=i+2;j<N;j++)
    {
        double sum=0.0;
        for(int k=i+1;k<j;k++)
            sum+=ABS(arr[k]-Lin_Inter(i,j,k));
        Sum[i][j]=sum;
    }
}


double f(int idx,int n)
{
   if(n<2) return Sum[0][idx];

   double&ret=cache[idx][n];
   if(ret>-0.5) return ret;
    ret=INF;
   for(int i=0;i<idx;i++)ret=min(ret,f(i,n-1)+Sum[i][idx]);
   return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        memset(cache,-1.0,sizeof(cache));
        cin>>N>>C;
        arr.resize(N,0);
        for(int i=0;i<N;i++)cin>>arr[i];
        sort(arr.begin(),arr.end());
        getSum();
        cout<<fixed;
        cout.precision(4);

        cout<<f(N-1,C-1)/(double)N<<"\n";
    }
}
