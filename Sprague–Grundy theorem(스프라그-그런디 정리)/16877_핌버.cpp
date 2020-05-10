#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
const int MAX_N=3000001;
int N,cache[MAX_N];
vector<int>fibo;

void getFibo()
{
    fibo.push_back(1);
    fibo.push_back(2);
    int size=2;
    while(fibo[size-2]+fibo[size-1]<=MAX_N)
    {
        fibo.push_back(fibo[size-2]+fibo[size-1]);
        size++;
    }
}

int getNim(int n)
{
    if(n==0)return 0;
    int&ret=cache[n];
    if(ret!=-1)return ret;
    int visited=0;
    for(auto i:fibo)
    {
        if(i>n)break;
        visited|=(1<<getNim(n-i));
    }
    //max nim number=16
    for(int i=0;i<17;i++)
        if(!(visited&(1<<i)))return ret=i;
    //error
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    memset(cache,-1,sizeof(cache));
    getFibo();
    int k=0;
    while(N--)
    {
        int tmp;
        cin>>tmp;
        k^=getNim(tmp);
    }
    cout<<(k>0?"koosaga":"cubelover");
}
