#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int MAX_N=1000000+2,MAX_ANS=1050000;
bool isPrime[MAX_ANS];
vector<int>Prime;

void getPrime()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=false;
    for(int i=2;i<MAX_ANS;i++)
    {
        if(isPrime[i])
        {
            Prime.push_back(i);
            for(int j=i*2;j<MAX_ANS;j+=i) isPrime[j]=false;
        }
    }
}

bool isPelindrom(int n)
{
    string s=to_string(n);
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])return false;
    return true;
}

int main()
{
    getPrime();
    int N;
    cin>>N;
    for(auto i:Prime)
        if(isPelindrom(i)&&i>=N)
    {
        cout<<i;
        return 0;
    }
}
