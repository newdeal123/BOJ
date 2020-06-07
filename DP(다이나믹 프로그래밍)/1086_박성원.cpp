#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int N,K;
ll cache[2<<15][101];
int arr[16][101];
vector<string>num;

int connected(int a,char b)
{
    string s=to_string(a);
    s.push_back(b);
    return stoi(s);
}

//(n+s)%K
int getK(int n,string s)
{
    string str=to_string(n);
    str+=s;
    int ans=0;
    for(auto c:str)
        ans=(connected(ans,c)%K);
    return ans%K;

}

ll GCD(ll a,ll b)
{
    if(b==0)return a;
    return GCD(b,a%b);
}

ll factorial(int n)
{
    if(n==1)return 1;
    else return factorial(n-1)*n;
}

ll f(int bits,int k)
{
    if(bits==(1<<N)-1)return(k==0?1:0);
    ll&ret=cache[bits][k];
    if(ret!=-1)return ret;
    ret=0;

    for(int i=0;i<N;i++)
        if(!(bits&(1<<i))) ret+=f(bits|(1<<i),arr[i][k]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache,-1,sizeof(cache));
    cin>>N;
    num.resize(N);
    for(auto&s:num)cin>>s;
    cin>>K;
    for(int i=0;i<N;i++)
    {
        for(int k=0;k<K;k++)
            arr[i][k]=getK(k,num[i]);
    }
    ll gcd=GCD(f(0,0),factorial(N));
    cout<<f(0,0)/gcd<<"/"<<factorial(N)/gcd;
}
