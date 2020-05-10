#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,sum[100002]={0,};
    cin>>N;
    vector<int>v(N);
    for(auto&i:v)
    {
        cin>>i;
        sum[i]++;
    }
    for(int i=1;i<=100000;i++)if(sum[i]%2!=0){cout<<"koosaga";return 0;}
    cout<<"cubelover";
}
