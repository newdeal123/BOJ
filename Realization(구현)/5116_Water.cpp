#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main ()
{
	int t;
	cin>>t;
	for(int data =1;data<=t;data++)
    {
        int n,m,minSize,board[51][51],pSum[51][51]={0,};
        cin>>n>>m>>minSize;
        int retX=0,retY=1;
        string s;
        cin>>s;
        for(int i=1;i<=n;i++)
            {
                string tmp;
                cin>>tmp;
                for(int j=1;j<=m;j++)
                board[i][j]=tmp[j-1];
            }
        for(int i=1;i<=n;i++)
        {
            bool flag=false;
            for(auto c:s)
                if(c==board[i][1]) flag=true;
            pSum[i][1]=pSum[i-1][1]+ flag;
        }
         for(int i=1;i<=m;i++)
        {
            bool flag=false;
            for(auto c:s)
                if(c==board[1][i]) flag=true;
            pSum[1][i]=pSum[1][i-1]+ flag;
        }
        for(int i=2;i<=n;i++)
            for(int j=2;j<=m;j++)
            {
                bool flag=false;
                for(auto c:s)
                    if(c==board[i][j]) flag=true;
                    pSum[i][j]=pSum[i-1][j]+pSum[i][j-1]-pSum[i-1][j-1]+flag;
            }
         /*for(int i=1;i<=n;i++)
            {for(int j=1;j<=m;j++)
                cout <<pSum[i][j]<<" ";
                cout <<endl;
            }*/
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int i2=i+minSize-1;i2<=n;i2++)
                    for(int j2=j+minSize-1;j2<=m;j2++)
            {
                int sum=pSum[i2][j2]-pSum[i-1][j2]-pSum[i2][j-1]+pSum[i-1][j-1];
                if((double)sum/(double)((i2-i+1)*(j2-j+1))>(double)retX/(double)retY)
                {
                    retX=sum,retY=(i2-i+1)*(j2-j+1);
                }
                if((double)sum/(double)((i2-i+1)*(j2-j+1))== (double)retX/(double)retY &&(i2-i+1)*(j2-j+1)>retY)
                {
                    retX=sum,retY=(i2-i+1)*(j2-j+1);
                }
            }
        cout << "Data Set " << data <<":\n"<<retX<<"/"<<retY<<"\n\n";

    }


}
