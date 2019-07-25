#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
int arr[100000+2];

int GCD(int a,int b)
{
    if(!b) return a;
    return GCD(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true)
    {
        int n,ans=0;
        cin>>n;
        if(!n) break;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=1;i<101;i++)
        {
            bool flag=false;
            int prev=-1;
            
            for(int j=0;j<n;j++)
            {
                if(arr[j]%i!=0)
                {
                    prev=-1;
                    continue;
                }
                if(prev==-1)prev=arr[j];
                else prev=GCD(prev,arr[j]);
                
                if(prev==i) flag=true;
            }
            if(flag)ans++;
        }
        cout<<ans<<"\n";
    }
}
