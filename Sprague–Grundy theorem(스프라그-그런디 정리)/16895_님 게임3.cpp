#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int cnt=0,n,k=0;
    cin>>n;
    vector<int>v(n);
    for(auto&i:v)cin>>i;

    for(int i=0;i<n;i++)
    {
        for(int k=0;k<v[i];k++)
        {
            int bit=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)bit^=k;
                else bit^=v[j];
            }
            if(bit==0)cnt++;
        }
    }
    cout<<cnt;
}
