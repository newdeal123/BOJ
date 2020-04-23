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


bool kmpSearch(const string&H,const string&N)
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

int main()
{
    string S,H,N;
    cin>>H>>N;
    for(auto&c:H)
        if(c<'0'||c>'9') S.push_back(c);
    //cout<<S<<endl;
    cout<<kmpSearch(S,N);
}
