#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N = 300000+2;
int n,k,goRight[MAX_N], goLeft[MAX_N];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    --k;
    memset(goRight,0,sizeof(goRight));
    memset(goLeft,0,sizeof(goLeft));

    vector<int>h(n);
    for(auto&i:h)cin>>i;
    cin>>s;

    for(int i=1; i<n; ++i)
        if(h[i-1]<=h[i])
    {
        if(s[i-1]=='T')s[i]='T';
        goRight[i]=1+goRight[i-1];
    }


    for(int i=n-2; i>=0; --i)
        if(h[i]>=h[i+1])
    {
        if(s[i+1]=='T')s[i]='T';
        goLeft[i]=1+goLeft[i+1];
    }

    int cnt=0,maxN=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='T')cnt++;
        else maxN=max(maxN,1+max(goRight[i],goLeft[i]));
    }

    if(s[k]=='T')cout<<cnt+maxN;
    else
    {
        int left=k,right=k;
        while(left>0&&h[left-1]==h[k])left--;
        while(right<n-1&&h[right+1]==h[k])right++;
        cout<<right-left+1+max(goRight[left],goLeft[right]);
    }


}
