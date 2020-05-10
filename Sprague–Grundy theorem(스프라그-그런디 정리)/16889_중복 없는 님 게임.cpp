#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <bitset>
using namespace std;
const int MAX_N=60;
int gNumber[MAX_N*2];

void getN()
{
    int now=1;
    for(int i=2;now<=MAX_N;i++)
    {
        int tmp=i;
        while(tmp--&&now<=MAX_N)
        {
            gNumber[now++]=i-1;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    getN();
    int N,k=0;
    cin>>N;
    while(N--)
    {
        int tmp;
        cin>>tmp;
        k^=gNumber[tmp];
    }
    if(k)cout<<"koosaga";
    else cout<<"cubelover";
}
