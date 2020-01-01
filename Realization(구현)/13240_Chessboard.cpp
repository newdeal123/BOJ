#include <iostream>
using namespace std;
int N,M,cnt=1;

char f(int n)
{
    if(n%2)return '*';
    else return '.';
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++,cout<<"\n",cnt+=1+(M%2==1))
        for(int j=1;j<=M;j++)
            cout<<f(cnt++);
}
