#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int N;
vector<int>mine,yours;

int main()
{
    int N,sum=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        yours.push_back(tmp);
    }
    sort(yours.begin(),yours.end());
    for(int j=1;j<yours.front();j++)
         mine.push_back(j);
    for(int i=0;i<N-1;i++)
    {
        for(int j=yours[i]+1;j<yours[i+1];j++)
            mine.push_back(j);
    }
    for(int j=yours.back()+1;j<=2*N;j++)
         mine.push_back(j);
    int myIdx=0;
    for(int yourIdx=0;yourIdx<N;yourIdx++)
    {
        while(mine[myIdx]<yours[yourIdx])
        {
            if(myIdx==N-1) break;
            myIdx++;
        }
        if(mine[myIdx]>yours[yourIdx]) {sum++;myIdx++;}
        if(myIdx==N) break;
    }
    cout<<sum;

}
