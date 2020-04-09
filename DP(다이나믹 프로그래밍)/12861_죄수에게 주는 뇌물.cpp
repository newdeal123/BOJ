#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
const int INF=987654321;
int P,Q,cache[103][103];
vector<int>idx_to_loc;
int loc_to_idx[10000+2];

int f(int leftIdx,int rightIdx)
{
    int&ret=cache[leftIdx][rightIdx];
    if(ret!=-1)return ret;
    ret=INF;
    bool found=false;
    for(int loc=idx_to_loc[leftIdx]+1;loc<idx_to_loc[rightIdx];loc++)
        if(loc_to_idx[loc])
    {
        found=true;
        ret=min(ret,f(leftIdx,loc_to_idx[loc])+f(loc_to_idx[loc],rightIdx)+(idx_to_loc[rightIdx]-idx_to_loc[leftIdx]-2));
    }
    if(!found)return ret=0;
    else return ret;
}


int main()
{
    memset(cache,-1,sizeof(cache));
    cin>>P>>Q;
    idx_to_loc={0,P+1};
    while(Q--)
    {
        int tmp;
        cin>>tmp;
        idx_to_loc.push_back(tmp);
    }
    sort(idx_to_loc.begin(),idx_to_loc.end());
    for(int i=0;i<idx_to_loc.size();i++)
        loc_to_idx[idx_to_loc[i]]=i;
    cout<<f(0,idx_to_loc.size()-1);
}
