#include <bits/stdc++.h>
using namespace std;
const int MAX_N=200+2;
int N,M,visited[MAX_N],house[MAX_N]={0,};
vector <int> node[MAX_N];

bool canIn(int idx)
{
   if(visited[idx])
        return false;
   visited[idx]=true;

   for(int i=0;i<node[idx].size();i++)
   {
        int next=node[idx][i];
       if(house[next]==0 || canIn(house[next]))
       {
           house[next]=idx;
           return true;
       }
   }

   return false;

}

int main()
{
    cin >> N >>M;
    for(int i=1;i<=N;i++)
    {
        int cnt;
        cin >>cnt;
        for(int j=0;j<cnt;j++)
        {
            int tmp;
            cin >>tmp;
            node[i].push_back(tmp);

        }
    }
    int ret=0;

    for(int i=1;i<=N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(canIn(i))
          ret++;
    }
    cout <<ret;
}
