#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAX_N=100000+2;
int N;
vector<int>v;
vector<ll>ans;


 struct SEG_TREE
 {
 	int n;
 	vector <ll> tree;
 	SEG_TREE() {;};
 	SEG_TREE(int len)
 	{
 		n = len;
 		tree.resize(n*4,0);
 	};
    ll update(int idx,int value){return update(idx,value,0,n-1,1);}
 	ll update(const int idx,const int value,int left,int right,int node)
 	{
 	    if(idx<left||right<idx)return tree[node];
 	    if(left==right)return tree[node]=value;
 	    int mid=(left+right)/2;
 	    return tree[node]=update(idx,value,left,mid,node*2)+update(idx,value,mid+1,right,node*2+1);
 	}
 	ll query(int left,int right) { return query(left,right,1,0,n-1);};
 	ll query(const int left,const int right,int node,int nodeLeft,int nodeRight)
 	{
 		if (right<nodeLeft||left>nodeRight) return 0;
 		if (left<=nodeLeft&&right>=nodeRight) return tree[node];
 		int mid=(nodeLeft+nodeRight)/2;
 		return query(left,right,node*2,nodeLeft,mid)+query(left,right,node*2+1,mid+1,nodeRight);

 	}
 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    v.resize(N),ans.resize(N);
    for(auto &i:v)cin>>i;
    vector<pair<int,int>>arr;
    for(int i=0;i<N;i++)arr.push_back({v[i],i});
    sort(arr.begin(),arr.end());

    SEG_TREE sumSEG(N),cntSEG(N);
    for(int i=0;i<N;i++)
    {
        ll value=arr[i].first,idx=arr[i].second;
       ll skip=(cntSEG.query(0,idx-1)*value)+(cntSEG.query(idx+1,N-1)*(value-1))-sumSEG.query(0,N-1);
       ans[idx]=(value-1)*N+idx+1-skip;
       //cout<<"idx "<<idx<<", skip:"<<skip<<", ans:"<<ans[idx]<<endl;
       cntSEG.update(idx,1);
       sumSEG.update(idx,value);
    }
    for(auto i:ans)cout<<i<<"\n";
}
