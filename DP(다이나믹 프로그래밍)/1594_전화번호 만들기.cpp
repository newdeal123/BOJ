#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000+2,INF=987654321;
int N,cache[MAX_N],arr[MAX_N];
string ans;

int f(int idx)
{
    //cout<<idx<<endl;
    if(idx==N)return 0;

    int&ret=cache[idx];
    if(ret!=-1)return ret;
    ret=-INF;
    if(idx+1<N)
    {
        if(arr[idx]==arr[idx+1])ret=max(ret,f(idx+2)+2);
        else ret=max(ret,f(idx+2));
    }
    if(idx+2<N)
    {
        if(arr[idx]==arr[idx+1]&&arr[idx+1]==arr[idx+2]) ret=max(ret,f(idx+3)+2);
        else if((arr[idx]==arr[idx+1]||(arr[idx+1]==arr[idx+2])||arr[idx]==arr[idx+2])) ret=max(ret,f(idx+3)+1);
        else ret=max(ret,f(idx+3));
    }
    return ret;
}

void output(int idx)
{
    if(idx==N)return;
    int ret1=-INF,ret2=-INF;
    if(idx+1<N)
    {
        if(arr[idx]==arr[idx+1])ret1=f(idx+2)+2;
        else ret1=f(idx+2);
    }
    if(idx+2<N)
    {
        if(arr[idx]==arr[idx+1]&&arr[idx+1]==arr[idx+2]) ret2=f(idx+3)+2;
        else if((arr[idx]==arr[idx+1]||(arr[idx+1]==arr[idx+2])||arr[idx]==arr[idx+2])) ret2=f(idx+3)+1;
        else ret2=f(idx+3);
    }


    if(ret1>=ret2)
    {
        ans+=arr[idx]+'0',ans+=arr[idx+1]+'0',ans+='-';
        return output(idx+2);
    }
    else
    {
        ans+=arr[idx]+'0',ans+=arr[idx+1]+'0',ans+=arr[idx+2]+'0',ans+='-';
        return output(idx+3);
    }
    return ;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)arr[i]=s[i]-'0';
    N=s.size();
    output(0);
    for(int i=0;i<ans.size()-1;i++)cout<<ans[i];
}
