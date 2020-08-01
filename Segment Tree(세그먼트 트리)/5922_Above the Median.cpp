#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=100000+5;
int arr[MAX_N*2]={0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,X,idx=MAX_N;
    cin>>N>>X;
    ll total=(ll)N*(N+1)/2,sum=0;
    arr[MAX_N]=1;
    
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp>=X) sum-=arr[++idx];
        else sum+=arr[idx--];

        arr[idx]++;
        total-=sum;
    }
    cout<<total;
}
