#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=987654321;

int lineY(int y,int arr[][4])
{
    int sum=0;
    for(int i=1;i<=3;i++)sum+=arr[y][i];
    return sum;
}
int lineX(int x,int arr[][4])
{
    int sum=0;
    for(int i=1;i<=3;i++)sum+=arr[i][x];
    return sum;
}
int lineCross(int arr[][4])
{
    int sum1=0,sum2=0;
    for(int i=1;i<=3;i++)sum1+=arr[i][i];
    for(int i=1;i<=3;i++)sum2+=arr[i][3-i+1];
    if(sum1!=sum2)return INF;
    else return sum1;
}

bool check_unique(int y,int x,int arr[][4])
{
    bool check[10]={0,};
    for(int i=1;i<=y;i++)
        for(int j=1;j<=x;j++)
            {
                if(check[arr[i][j]]) return false;
                check[arr[i][j]]=true;
            }
    return true;
}
int dfs(int y,int x,int arr[][4])
{
    if(!check_unique(y,x,arr)) return INF;
    if(x==3 && lineY(1,arr)!=lineY(y,arr)) return INF;
    if(y==3 && lineY(1,arr)!=lineX(x,arr)) return INF;
    if(y==3&&x==3)
    {
        if(lineY(1,arr)!=lineCross(arr)) return INF;
        else return 0;
    }
    int nextY=y+(x==3?1:0),nextX=x+(x==3?-2:1),ret=INF;
    for(int i=1;i<=9;i++)
    {
        int diff=abs(i-arr[nextY][nextX]),tmp=arr[nextY][nextX];
        arr[nextY][nextX]=i;
        ret=min(ret,dfs(nextY,nextX,arr)+diff);
        arr[nextY][nextX]=tmp;
    }
     return ret;
}

int main()
{
    int arr[4][4];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++) cin>>arr[i][j];
    cout<<dfs(1,0,arr);
}
