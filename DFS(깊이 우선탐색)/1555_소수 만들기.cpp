#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
const int INF=1e9+100;
const int MAX_V=10000000;
bool isPrime[MAX_V];
vector<int>smallPrime;
set<int>bigPrime;
int maxN=-INF,minN=INF;

void getPrime()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=false,isPrime[1]=false;
    for(int i=2;i<MAX_V;i++)
    {
        if(isPrime[i])
        {
            smallPrime.push_back(i);
            for(int j=2*i;j<MAX_V;j+=i)
                isPrime[j]=false;
        }
    }
}

bool is_prime(int n)
{
    if(n<=1)return false;
    if(n<MAX_V)return isPrime[n];
    if(bigPrime.find(n)!=bigPrime.end())return true;
    for(auto i:smallPrime)
        if(n%i==0)return false;
    bigPrime.insert(n);
    return true;
}

void change(int&value,int a,int b,int type)
{
    if(type==0)value=a+b;
    else if(type==1)value=a-b;
    else if(type==2)value=-a+b;
    else if(type==3)value=a*b;
    else if(type==4)value=a/b;
    else value=b/a;
}

void dfs(vector<int>&v,int idx)
{
    if(idx==1)
    {
        //cout<<v.front()<<endl;
        if(!is_prime(v.front()))return ;
        maxN=max(maxN,v.front());
        minN=min(minN,v.front());
        return ;
    }
    for(int i=0;i<idx-1;i++)
    {
        int left=v[i];
        for(int j=i+1;j<idx;j++)
        {
            int right=v[j];
            v[j]=v[idx-1];
            for(int k=0;k<6;k++)
            {
                if(k==4&&right==0)continue;
                if(k==5&&left==0)continue;
                change(v[i],left,right,k);
                dfs(v,idx-1);
            }
            v[idx-1]=v[j];
            v[j]=right;
        }
        v[i]=left;
    }
}

int main()
{
    getPrime();
    int N;
    cin>>N;
    vector<int>num(N);
    for(auto&i:num)cin>>i;
    dfs(num,N);

    if(maxN==-INF)cout<<-1;
    else cout<<minN<<endl<<maxN;
}
