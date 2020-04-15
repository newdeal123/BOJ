#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int INF=987654321;
int N,K;
vector<int> program[101];

vector<int>getPartialMatch(const vector<int>&N)
{
    int Nsize=N.size();
    vector<int>pi(Nsize,0);

    int begin=1,matched=0;
    while(begin+matched<=Nsize)
    {
        if(N[begin+matched]==N[matched])
        {
            matched+=1;
            pi[begin+matched-1]=matched;
        }
        else
        {
            if(matched==0)begin+=1;
            else
            {
                begin+=matched-pi[matched-1];
                matched=pi[matched-1];
            }
        }
    }
    return pi;
}


bool kmpSearch(const vector<int>&H,const vector<int>&N)
{
    int Hsize=H.size(),Nsize=N.size();
    vector<int>pi=getPartialMatch(N);

    int begin=0,matched=0;
    while(begin<=Hsize-Nsize)
    {
        if(matched<Nsize&&H[begin+matched]==N[matched])
        {
            matched+=1;
            if(matched==Nsize)return true;
        }
        else
        {
            if(matched==0)begin+=1;
            else
            {
                begin+=matched-pi[matched-1];
                matched=pi[matched-1];
            }
        }
    }
    return false;
}

bool dfs(int idx,const vector<int> &S,const vector<int> &rS)
{
    if(idx==N)return true;

    bool ret=max(kmpSearch(program[idx],S),kmpSearch(program[idx],rS));
    if(ret)return dfs(idx+1,S,rS);
    else return false;
}

int main()
{
    int minLen=INF;
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int len;
        cin>>len;
        minLen=min(minLen,len);
        program[i].resize(len);
        for(auto&j:program[i])cin>>j;
    }
    bool suc=false;
    for(int i=0;i<program[0].size()-K+1;i++)
    {
        vector<int>v,rv;
        for(int j=i;j<i+K;j++)v.push_back(program[0][j]);
        rv=v;
        reverse(v.begin(),v.end());
        /*if(dfs(1,v,rv))
        {
            for(auto i:rv)cout<<i<<" ";
            cout<<"\n";
        }*/
        suc=max(suc,dfs(1,v,rv));
    }
    if(suc)cout<<"YES";
    else cout<<"NO";
}
