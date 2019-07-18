#include <bits/stdc++.h>
using namespace std;
const int MAX_N=40+2;
int cache[MAX_N][MAX_N];
string s1,s2;

int f(int idx1,int idx2)
{
    if(idx1==s1.size() || idx2==s2.size()) return 0;

    int&ret= cache[idx1][idx2];
    if(ret !=-1) return ret;

    if(s1[idx1]==s2[idx2])
       ret=max(ret , f(idx1+1,idx2+1)+1);

    ret= max(ret, f(idx1+1,idx2));
    ret=max(ret,f(idx1,idx2+1));

    return ret;
}

void output(int idx1,int idx2)
{
    if(idx1==s1.size() || idx2==s2.size()) return;
    int ret1=0,ret2,ret3;
    if(s1[idx1]==s2[idx2])
        ret1=f(idx1+1,idx2+1)+1;
    ret2=f(idx1+1,idx2),ret3=f(idx1,idx2+1);
    if(ret1>ret2 && ret1>ret3)
    {
        cout << s1[idx1];
        return output(idx1+1,idx2+1);
    }
    if(ret2>ret3)
        return output(idx1+1,idx2);
    else return output(idx1,idx2+1);



}

int main()
{

    memset(cache,-1,sizeof(cache));
    cin >>s1 >>s2;
    f(0,0);
    output(0,0);
}
