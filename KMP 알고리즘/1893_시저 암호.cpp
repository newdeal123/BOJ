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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string A,W,S;
        cin>>A>>W>>S;
        int len=A.size();
        vector<int>ans;
        for(int shift=0;shift<len;shift++)
        {
            string N;
            for(auto c:W)
                for(int i=0;i<A.size();i++)
                    if(c==A[i])N.push_back(A[(i+shift)%len]);
            if(kmpSearch(S,N)==1)ans.push_back(shift);
        }
        if(ans.empty()) cout<<"no solution";
        else if(ans.size()==1) cout<<"unique: "<<ans.front();
        else
        {
            cout<<"ambiguous: ";
            for(auto i:ans)cout<<i<<" ";

        }
        cout<<"\n";
    }
}
