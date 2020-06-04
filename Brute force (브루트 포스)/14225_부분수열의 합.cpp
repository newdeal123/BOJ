#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int MAX_N=2000000+2;
int pSum[20+2]={0,};
bool visited[MAX_N]={0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    vector <int>v(N);
    for(auto&i:v)cin>>i;

    for(int bits=1;bits<(1<<N);bits++)
    {
        int sum=0;
        for(int i=0;i<N;i++)
            if(bits&(1<<i))sum+=v[i];
        visited[sum]=true;
    }

    for(int i=1;i<MAX_N;i++)
        if(!visited[i])
    {
        cout<<i;
        break;
    }
}
