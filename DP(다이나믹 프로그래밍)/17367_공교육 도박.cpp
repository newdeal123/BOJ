#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
double cache[1000][7][7];
int N;

int getPrice(int llast,int last,int now)
{
    if(llast==last&&last==now)return 10000+now*1000;
    else if(llast==last)return 1000+last*100;
    else if(last==now)return 1000+now*100;
    else if(llast==now)return 1000+llast*100;
    else return max(max(llast,last),now)*100;
}

double f(int roll,int llast,int last)
{
    if(roll==N)return 0.0;
    double&ret=cache[roll][llast][last];
    if(ret>-0.5)return ret;
    ret=0;
    for(int i=1;i<=6;i++)
    {
        if(roll<2)ret+=f(roll+1,last,i)/6.0;
        else ret+=max(f(roll+1,last,i)/6.0,getPrice(llast,last,i)/6.0);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>N;
    cout<<fixed;
    cout.precision(7);
    cout<<f(0,0,0);
}
