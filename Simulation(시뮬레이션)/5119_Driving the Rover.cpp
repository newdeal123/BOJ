#include <bits/stdc++.h>
using namespace std;
int goY[4]={-1,0,1,0};
int goX[4]={0,-1,0,1};

struct CAR
{
    int y,x,direct,speed;
};

void Order(CAR& c,string s)
{
    if(s=="FORWARD")
        if(c.speed==0)c.speed=1;
    if(s=="BACKWARD")
       if(c.speed==0)c.speed=-1;
    if(s=="RIGHT")
      if(c.speed==0)c.direct=(c.direct+1)%4;
    if(s=="LEFT")
       if(c.speed==0)c.direct=(c.direct+3)%4;
    if(s=="STOP")
        c.speed=0;
    if(s=="FASTER")
        if(c.speed>0) c.speed=min(5,c.speed+1);
    if(s=="SLOWER")
        if(c.speed>0) c.speed-=1;
    c.y=c.y+goY[c.direct]*c.speed,c.x=c.x+goX[c.direct]*c.speed;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,cnt=1;
    cin >>t;
    while(t--)
    {
        CAR mySummerCar={0,0,2,0};
        int order;
        cin >>order;
        while(order--)
        {
            string s;
            cin >> s;
            Order(mySummerCar,s);
        }
        cout <<"Data Set "<<cnt++<<":\n"<<mySummerCar.x<<" "<<mySummerCar.y<<"\n\n";
    }
    return 0;
}
