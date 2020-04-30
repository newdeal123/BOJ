#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD=100003;
int len;
string S;

int mod(ll n)
{
    if(n>=0)return n%MOD;
    else return ((-n/MOD+1)*MOD+n)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>len>>S;

    int left=0,right=len,ans;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int H=0,power=1;
        vector<int>pos[MOD];
        bool found=false;

        for(int i=0;i<len-mid+1;i++)
        {
            if(i==0)
            {
                for(int j=0;j<mid;j++)
                {
                    H=mod(H+(ll)S[mid-1-j]*power);
                    if(j<mid-1)power=mod((ll)power*2);
                }
            }
            else H=mod(2*(H-(ll)S[i-1]*power)+S[i+mid-1]);

            if(!pos[H].empty())
            {
                  for(auto p:pos[H])
                  {
                      bool same=true;
                      for(int j=0;j<mid;j++)
                        if(S[i+j]!=S[p+j])
                      {
                          same=false;
                          break;
                      }
                      if(same)
                      {
                          found=true;
                          break;
                      }
                  }
            }
            if(found)break;
            else pos[H].push_back(i);
        }

        if(found)
        {
            left=mid+1;
            ans=mid;
        }
        else right=mid-1;
    }
    cout<<ans;

}
