#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int GCD(int a,int b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

int main()
{
    int R,G;
    cin>>R>>G;
    int K=GCD(R,G);
    for(int i=1;i<=K;i++)
    {
        if(R%i==0&&G%i==0)
        {
            cout<<i<<" "<<R/i<<" "<<G/i<<"\n";
        }
    }
}
