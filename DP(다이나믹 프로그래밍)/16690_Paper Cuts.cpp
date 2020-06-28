#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int INF=987654321;
int N;
string s1,s2;
int cache[1<<18];

int f(int bits)
{
    if(bits==0)return 0;
    int&ret=cache[bits];
    if(ret!=-1)return ret;
    ret=INF;
    int idx=0;
    for(int i=0;i<N;i++)
        if(!(bits&(1<<i)))idx++;
    for(int i=idx;i<N;i++)
    {
        int width=i-idx+1;
        //s1 range:(left~right)
        //s2 range:(idx~i)
        for(int left=0;left<N-width+1;left++)
        {
            int right=left+width-1;
            bool allExist=true;
            for(int j=0;j<width;j++)if(!(bits&(1<<(left+j)))||s1[left+j]!=s2[idx+j])allExist=false;
            if(!allExist)continue;

            //cout<<left<<"~"<<right<<endl;
           // cout<<idx<<"~"<<i<<endl<<endl;
            int cut=0;
            if(left!=0&&bits&(1<<(left-1)))cut++;
            if(right!=N-1&&bits&(1<<(right+1)))cut++;

            int nextBits=bits;
            for(int j=left;j<=right;j++)nextBits^=(1<<j);

            ret=min(ret,f(nextBits)+cut);
        }
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>s1>>s2;
    N=s1.size();
    cout<<f((1<<N)-1);
}
