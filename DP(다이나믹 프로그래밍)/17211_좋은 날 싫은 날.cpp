#include <bits/stdc++.h>
using namespace std;
int N,M;
double cache[102][2];
double g_to_g,g_to_b,b_to_g,b_to_b;

double good_f(int days, bool good)
{
    if(days==N+1)
    {
        if(good)return 1.0;
        else return 0.0;
    }

    double& ret= cache[days][good];
    if(ret > -0.5)
        return ret;
    if(good)
        return ret= good_f(days+1,1)*g_to_g + good_f(days+1,0)*(g_to_b);
    else
        return ret=good_f(days+1,1)*b_to_g + good_f(days+1,0)*(b_to_b);
}
\
int main()
{
    for(int i=0;i<102;i++)
        for(int j=0;j<2;j++)
        cache[i][j]=-1.0;
    cin >>N>>M;
    cin >> g_to_g >> g_to_b >> b_to_g >> b_to_b;
    double ans=good_f(1,!M);
    cout <<round(ans*1000.0) <<"\n";
    cout <<round((1.0-ans)*1000.0);
}
