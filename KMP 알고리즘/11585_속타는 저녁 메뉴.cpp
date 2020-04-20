#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
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


int kmpSearch(const string&H,const string&N)
{
    int ret=0;
    int Hsize=H.size(),Nsize=N.size();
    vector<int>pi=getPartialMatch(N);

    int begin=0,matched=0;
    while(begin<=Hsize-Nsize)
    {
        if(matched<Nsize&&H[begin+matched]==N[matched])
        {
            matched+=1;
            if(matched==Nsize)ret++;
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

int GCD(int a,int b)
{
    if(b==0)return a;
    return GCD(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int len,cnt;
    string H,N;
    cin>>len;
    H.resize(len),N.resize(len);

    for(auto&i:H)cin>>i;
    for(auto&i:N)cin>>i;

    for(int i=0;i<len-1;i++)
        H.push_back(H[i]);
    cnt=kmpSearch(H,N);
    cout<<cnt/GCD(cnt,len)<<"/"<<len/GCD(cnt,len);

}
