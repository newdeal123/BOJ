#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
int N,K;
vector<int>score;

bool is_possible(int mid)
{
    int cnt=0,sum=0;
    for(auto i:score)
    {
        if(i>mid)return false;
        else if(sum+i>mid) cnt++,sum=0;
        else sum+=i;
    }
    if(cnt+1<=K)return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    score.resize(N);
    for(int i=0;i<N;i++)cin>>score[i];
    int left=0,right=2000000+2,ret;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ret;

}
