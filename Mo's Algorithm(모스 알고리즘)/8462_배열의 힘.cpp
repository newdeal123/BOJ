#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX_N=(int)1e5+2;
int N,q,sqrtN,visited[MAX_N*10]={0,};
ll cnt=0,ans[MAX_N];
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

ll getplusK(int idx)
{
    return -arr[idx]*pow(visited[arr[idx]]++,2)+arr[idx]*pow(visited[arr[idx]],2);
}
ll getminusK(int idx)
{
    return arr[idx]*pow(visited[arr[idx]]--,2)-arr[idx]*pow(visited[arr[idx]],2);
}

void getFirst()
{
    queryLeft=query[0].left,queryRight=query[0].right;
    for(int i=queryLeft;i<queryRight;i++)
            cnt+=getplusK(i);

    ans[query[0].idx]=cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>q;
    sqrtN=sqrt(N);
    arr.resize(N);
    for(int i=0;i<N;i++)
        cin>>arr[i];

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
        while(now.left<queryLeft) cnt+=getplusK(--queryLeft);
        while(now.left>queryLeft) cnt-=getminusK(queryLeft++);
        while(queryRight<now.right) cnt+=getplusK(queryRight++);
        while(queryRight>now.right) cnt-=getminusK(--queryRight);
        ans[now.idx]=cnt;
    }

    for(int i=0;i<q;i++)cout<<ans[i]<<"\n";

}
