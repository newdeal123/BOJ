#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<n/2+m/2<<"\n";
    for(int i=2;i<=n;i+=2) cout<<i<<" 1 "<<i<<" "<<m<<"\n";
    for(int j=2;j<=m;j+=2) cout<<"1 "<<j<<" "<<n<<" "<<j<<"\n";

}
