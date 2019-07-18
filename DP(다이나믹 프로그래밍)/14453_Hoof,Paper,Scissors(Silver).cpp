#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100000+2;
int cache[MAX_N][3][2],N;
int order[MAX_N];

enum
{
    Hoof,Paper,Scissors
};

bool Win(int a,int b)
{
    if(a==Hoof && b==Scissors) return true;
    if(a==Paper && b==Hoof) return true;
    if(a==Scissors && b==Paper) return true;

    return false;
}

int f(int idx,int type,bool chance)
{
    if(idx==N) return 0;
    int&ret=cache[idx][type][chance];
    if(ret!=-1) return ret;
    if(!chance) return ret=f(idx+1,type,chance)+Win(type,order[idx]);

    ret=max(ret,f(idx+1,type,chance)+Win(type,order[idx]));
    type=(type+1==3)?0:type+1;
    ret=max(ret,f(idx+1,type,0)+Win(type,order[idx]));
    type=(type+1==3)?0:type+1;
    ret=max(ret,f(idx+1,type,0)+Win(type,order[idx]));
    return ret;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache,-1,sizeof(cache));
    cin>>N;
    for(int i=0;i<N;i++)
        {
            char c;
            cin>>c;
            if(c=='P')order[i]=Paper;
            else if(c=='H')order[i]=Hoof;
            else order[i]=Scissors;
        }
    cout<<max(f(0,Hoof,1),max(f(0,Paper,1),f(0,Scissors,1)));
}
