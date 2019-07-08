#include<bits/stdc++.h>
using namespace std;
const int MAX_N=75000+2;
int N;
vector<pair<int,int>> island;

bool compareY(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}

bool compare(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.second>b.second;
}

struct SEG_TREE
{
    int n;
    vector<int>tree;
    SEG_TREE(){;};
    SEG_TREE(int s)
    {
        n=s;
        tree.resize(n*4,0);
    }
    int update(int k) {return update(k,0,n-1,1);};
    int update(const int k,int left,int right,int node)
    {
        if(k<left||right<k) return tree[node];
        if(left==right) return ++tree[node];
        int mid=(left+right)/2;
        return tree[node]=update(k,left,mid,node*2)+update(k,mid+1,right,node*2+1);
    }
    int query(int left,int right){return query(left,right,0,n-1,1);};
    int query(const int left,const int right,int nodeLeft,int nodeRight,int node)
    {
        if(nodeRight<left||nodeLeft>right) return 0;
        if(left<=nodeLeft && nodeRight<=right) return tree[node];
        int mid=(nodeLeft+nodeRight)/2;
        return query(left,right,nodeLeft,mid,node*2)+query(left,right,mid+1,nodeRight,node*2+1);
    }
};


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long long sum=0;
        island.clear();
        cin>>N;
        SEG_TREE seg(MAX_N);
        for(int i=0;i<N;i++)
        {
            int x,y;
            cin>>x>>y;
            island.push_back(make_pair(x,y));
        }
        sort(island.begin(),island.end(),compareY);
        int cnt=0,numY[MAX_N];
        numY[0]=cnt;
        for(int i=1;i<island.size();i++)
            {
                if(island[i].second!=island[i-1].second) cnt++;
                numY[i]=cnt;
            }
        for(int i=0;i<island.size();i++)
            island[i].second=numY[i];

        sort(island.begin(),island.end(),compare);
        for(auto i:island)
            {
                sum+=seg.query(i.second,MAX_N);
                seg.update(i.second);
            }
        cout<<sum<<"\n";
    }
}
