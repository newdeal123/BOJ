#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
const int MAX_N=(int)1e6+2,MAX_NUM=(int)1e6+2;
int N,q,sqrtN,cnt=0,visited[MAX_NUM]={0,},ans[MAX_N];
int queryLeft,queryRight;
vector<int>arr;


struct MOS_QUERY
{
    int left,right,idx;
    MOS_QUERY(){;}
    MOS_QUERY(int left,int right,int idx){this->left=left,this->right=right,this->idx=idx;}
};
vector<MOS_QUERY> query;

bool compare(MOS_QUERY &a,MOS_QUERY &b)
{
    if(a.left/sqrtN!=b.left/sqrtN)return a.left/sqrtN<b.left/sqrtN;
    else return a.right<b.right;
}

void getFirst()
{
    queryLeft=query[0].left,queryRight=query[0].right;
    for(int i=queryLeft;i<queryRight;i++)
        if(visited[arr[i]]++ ==0) cnt+=1;
    ans[query[0].idx]=cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    sqrtN=sqrt(N);
    arr.resize(N);
    int mpCnt=1;
    map<int,int>mp;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        if(mp.find(tmp)==mp.end())
            mp.insert({tmp,mpCnt++});
        arr[i]=mp[tmp];
    }

    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        query.push_back(MOS_QUERY(a-1,b,i));
    }
    sort(query.begin(),query.end(),compare);
    getFirst();
    for(int i=1;i<q;i++)
    {
        MOS_QUERY now=query[i];
        while(now.left<queryLeft)
            if(visited[arr[--queryLeft]]++ ==0) cnt+=1;
        while(now.left>queryLeft)
            if(--visited[arr[queryLeft++]] ==0) cnt-=1;
        while(queryRight<now.right)
            if(visited[arr[queryRight++]]++ ==0) cnt+=1;
        while(queryRight>now.right)
            if(--visited[arr[--queryRight]] ==0) cnt-=1;
        ans[now.idx]=cnt;
    }

    for(int i=0;i<q;i++)cout<<ans[i]<<"\n";

}
