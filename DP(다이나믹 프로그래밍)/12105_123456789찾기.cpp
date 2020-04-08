#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MOD=(int)1e9+7;
string P,S;
int N,cache[10000][2][2][4][3];
vector<int>v;

vector<int>getPartialMatch(const string&N)
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


vector<int> kmpSearch(const string&H,const string&N)
{
    int Hsize=H.size(),Nsize=N.size();
    vector<int>ret;
    vector<int>pi=getPartialMatch(N);

    int begin=0,matched=0;
    while(begin<=Hsize-Nsize)
    {
        if(matched<Nsize&&H[begin+matched]==N[matched])
        {
            matched+=1;
            if(matched==Nsize)ret.push_back(begin+1);
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
    return ret;
}

int getIn2(int n)
{
    if(n%2!=0)return 0;
    else return getIn2(n/2)+1;
}
int getIn3(int n)
{
    if(n%3!=0)return 0;
    else return getIn3(n/3)+1;
}

int f(int idx,int cnt5,int cnt7,int cnt2,int cnt3)
{
    if(idx==N)
    {
        if(cnt5==1&&cnt7==1&&cnt2==3&&cnt3==2) return 1;
        else return 0;
    }

    int&ret=cache[idx][cnt5][cnt7][cnt2][cnt3];
    if(ret!=-1)return ret%MOD;
    ret=0;
    int nextCnt5=(v[idx]%5==0?cnt5+1:cnt5);
    int nextCnt7=(v[idx]%7==0?cnt7+1:cnt7);
    int nextCnt2=(v[idx]%2==0?cnt2+getIn2(v[idx]):cnt2);
    int nextCnt3=(v[idx]%3==0?cnt3+getIn3(v[idx]):cnt3);
    return ret=(f(idx+1,cnt5,cnt7,cnt2,cnt3)+
                f(idx+1,min(1,nextCnt5),min(1,nextCnt7),min(3,nextCnt2),min(2,nextCnt3)))%MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>P>>S;
    for(int i=0;i<S.size()-P.size()+1;i++)
    {
        bool same=true;
        for(int j=0;j<P.size();j++)
            if(S[i+j]!=P[j])
        {
            same=false;
            break;
        }
        if(same)v.push_back(i+1);
    }
    N=v.size();
    //for(auto&i:v)cout<<i<<" ";
    cout<<f(0,0,0,0,0);
}
