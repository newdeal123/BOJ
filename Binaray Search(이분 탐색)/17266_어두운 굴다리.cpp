#include <bits/stdc++.h>
using namespace std;
const int MAX_N=(int)1E6+1;
const int INF=987654321;
int N,M;
vector <int>v;

bool is_possible(int h)
{
    bool visited[MAX_N]={0,};
    if(v.front()-h>0 || v.back()+h<N) return false;
    int covered=0;
    for(auto i:v)
    {
        if(covered<i-h) return false;
        covered=i+h;
    }
    return true;
}

int main()
{
    ios_base :: sync_with_stdio(false);
     cin.tie(NULL); 
     cout.tie(NULL);

    cin>>N>>M;
    v.resize(M);
    for(int i=0;i<M;i++)
        cin>>v[i];

    int left=0,right=(int)1E6+1,ret=INF;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=min(ret,mid);
            right=mid-1;
        }
        else
            left=mid+1;
    }
    cout <<ret;
}
