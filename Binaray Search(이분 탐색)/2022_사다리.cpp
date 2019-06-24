#include <bits/stdc++.h>
using namespace std;
double x,y,c;

bool is_possible(double mid)
{
    double h1=sqrt(x*x-mid*mid);
    double h2=sqrt(y*y-mid*mid);

    return (h1*h2)/(h1+h2)>=c;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>x>>y>>c;
    double left=0.0,right=min(x,y),ret=0.0;
    while(left+0.000001<right)
    {
        double mid=(left+right)/2.0;
        if(is_possible(mid))
        {
            ret=max(ret,mid);
            left=mid;
        }
        else
            right=mid;
    }
    cout<<fixed;
    cout.precision(3);
    cout<<ret;
}
