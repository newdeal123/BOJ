#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

int GCD(int a,int b)
{
    if(!b)return a;
    return GCD(b,a%b);
}
bool inf[2000+2][2000+2];

int main()
{
    int a,b;
    cin>>a>>b;
    int sum=0;
    memset(inf,0,sizeof(inf));
    for(int i=a;i<=b;i++)
    {
        for(int j=1;j<=i;j++)
           {
               int gcd=GCD(i,j);
               if(!inf[j/gcd][i/gcd])
               {
                   inf[j/gcd][i/gcd]=true;
                   sum++;
               }
           }
    }
    cout<<sum;
}
