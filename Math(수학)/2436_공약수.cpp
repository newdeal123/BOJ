#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int GCD(int a,int b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

int main()
{
    int A,B;
    cin>>A>>B;
    pair<int,int>ans;
    for(int i=1;i<=sqrt(B/A);i++)
        if((B/A)%i==0 && GCD(i,(B/A)/i)==1)
        ans={i,(B/A)/i};
    cout<<min(ans.first,ans.second)*A<<" "<<max(ans.first,ans.second)*A;
}
