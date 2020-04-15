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


int main()
{
    while(true)
    {
        string S;
        cin>>S;
        int len=S.size();
        if(S==".")break;
        vector<int>pi=getPartialMatch(S);
        if(len%(len-pi[len-1])==0)cout<<len/(len-pi[len-1]);
        else cout<<1;
        cout<<"\n";

    }
}
