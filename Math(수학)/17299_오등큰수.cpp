#include<bits/stdc++.h>
using namespace std;
const int MAX_N=(int)1e6+2;
int N,arr[MAX_N],ans[MAX_N],F[MAX_N]={0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(ans,-1,sizeof(ans));
    stack<int>stk;
    cin>>N;
    for(int i=0;i<N;i++)
        {
            cin>>arr[i];
            F[arr[i]]++;
        }
    stk.push(0);
    for(int i=1;i<N;i++)
    {
        while(!stk.empty() && F[arr[stk.top()]]<F[arr[i]])
        {
            ans[stk.top()]=arr[i];
            stk.pop();
        }
            stk.push(i);
    }
    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";
}
