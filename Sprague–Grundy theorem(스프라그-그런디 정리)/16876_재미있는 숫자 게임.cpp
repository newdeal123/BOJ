#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int N,M,cache[10000][101];

//1:koosaga 0:cubelover
//if koosaga can Win?
int whoWin(int now,int turn)
{
    if(turn==0)return(now>N?1:0);
    int&ret=cache[now][turn];
    if(ret!=-1)return ret;
    int minN=1,maxN=0;
    string s;
    for(int i=0;i<4-to_string(now).size();i++)s+="0";
    s+=to_string(now);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='9')s[i]='0';
        else s[i]++;

        minN=min(minN,whoWin(stoi(s),turn-1));
        maxN=max(maxN,whoWin(stoi(s),turn-1));

        if(s[i]=='0')s[i]='9';
        else s[i]--;
    }
    //if koosaga turn
    if((M-turn)%2==0)return maxN;
    else return ret=minN;
}

int main()
{
    cin>>N>>M;
    memset(cache,-1,sizeof(cache));
    cout<<(whoWin(N,M)==1?"koosaga":"cubelover");
}
