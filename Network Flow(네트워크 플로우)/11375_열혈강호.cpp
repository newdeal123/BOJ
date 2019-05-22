#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000+2;
int N,M,visited[MAX_N],working[MAX_N]={0,};
vector <int> work[MAX_N];

//idx번 노동자가 일을 할수있는가
bool canWork(int idx)
{
    if(visited[idx])
        return false;
    visited[idx]=true;

    for(int i=0;i<work[idx].size();i++)
    {
        int next=work[idx][i];
        //next번 일을 하고있는 사람이 없거나, 그 일을 하고있는사람이 다른 일을 할수 있으면
        if(!working[next] || canWork(working[next]))
        {
            working[next]=idx;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
     cin.tie(NULL); cout.tie(NULL);

    cin >>N >>M;
    for(int i=1;i<=N;i++)
    {
        int t;
        cin >>t;
        while(t--)
        {
            int tmp;
            cin >>tmp;
            work[i].push_back(tmp);
        }
    }
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        memset(visited,0,sizeof(visited));
        if(canWork(i)) cnt++;
    }
    cout <<cnt;

}
