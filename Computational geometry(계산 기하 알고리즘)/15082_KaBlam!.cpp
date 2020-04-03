#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <string.h>
#include <stack>
using namespace std;
const double PI = 2.0*acos(0.0);

int main()
{
    cout<<fixed;
    cout.precision(8);
    int Xm,Vx,Vy,Xa,Va,Tk;
    cin>>Xm>>Vx>>Vy>>Xa>>Va>>Tk;
    pair <double,double>Kablam={Vx*Tk+Xm-Xa,Tk*Tk*(-16)+Vy*Tk};
    //cout<<Kablam.first<<" "<<Kablam.second<<"\n";
    double time=(double)Tk-sqrt(Kablam.first*Kablam.first+Kablam.second*Kablam.second)/Va;
    if(Kablam.second<=0||time<=0){cout<<"start running";return 0;}
    cout<<time<<" "<<atan(Kablam.second/Kablam.first)*180.0/PI;
}
