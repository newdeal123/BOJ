#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=500000+2,INF=987654321;
int N,Rcnt=0,Bcnt=0;
string s;

int main()
{
    cin>>N>>s;
    for(auto c:s)
    {
        if(c=='R')Rcnt++;
        else Bcnt++;
    }
    int minN=INF,cnt=0,idx=0;
    //left에 R을 모은다.
    while(s[idx++]=='R'){cnt++;}
    minN=min(minN,Rcnt-cnt);
    //left에 R를 모은다.
    idx=N-1,cnt=0;
    while(s[idx--]=='R'){cnt++;}
    minN=min(minN,Rcnt-cnt);

    idx=0,cnt=0;
    while(s[idx++]=='B'){cnt++;}
    minN=min(minN,Bcnt-cnt);

    idx=N-1,cnt=0;
    while(s[idx--]=='B'){cnt++;}
    minN=min(minN,Bcnt-cnt);

    cout<<minN;
}
