#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=100000;
int N,Q,sqrtN;
vector<int>v;
int qAns=0,cnt[MAX_N*2+2]={0,},rcnt[MAX_N*2+2]={0,},ans[MAX_N+2]={0,};

struct queryNode
{
    int left=0,right=0,idx=0;
    bool operator<(const queryNode &y)const
    {
        if(left/sqrtN!=y.left/sqrtN)return (left/sqrtN<y.left/sqrtN);
        else return (right<y.right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>Q;
    sqrtN=sqrt(N);
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp+MAX_N);
    }
    queryNode query[MAX_N+2];
    for(int i=0;i<Q;i++)
    {
        int left,right;
        cin>>left>>right;
        query[i]={left-1,right,i};
    }
    sort(query,query+Q);
    int qLeft=query[0].left,qRight=query[0].right;

    for(int i=qLeft;i<qRight;i++)
        {
            int tmp=++cnt[v[i]];
            ++rcnt[tmp];
            if(tmp>qAns)++qAns;
        }
    ans[query[0].idx]=qAns;

    for(int i=1;i<Q;i++)
    {
        int tmp;
        while(query[i].left<qLeft)
        {
            tmp=++cnt[v[--qLeft]];
            ++rcnt[tmp];
            if(tmp>qAns)qAns++;
        }
        while(query[i].right>qRight)
        {
            tmp=++cnt[v[qRight++]];
            ++rcnt[tmp];
            if(tmp>qAns)qAns++;
        }
        while(query[i].left>qLeft)
        {
            tmp=cnt[v[qLeft++]]--;
            if(--rcnt[tmp]==0&&tmp==qAns)qAns--;
        }
        while(qRight>query[i].right)
        {
            tmp=cnt[v[--qRight]]--;
            if(--rcnt[tmp]==0&&tmp==qAns)qAns--;
        }
        ans[query[i].idx]=qAns;
    }
    for(int i=0;i<Q;i++)cout<<ans[i]<<"\n";
}
