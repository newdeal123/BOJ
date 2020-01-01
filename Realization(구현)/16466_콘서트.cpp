#include<bits/stdc++.h>
using namespace std;
int N;
vector<int>v;

int getNum()
{
    if(v.front()!=1) return 1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[i-1]!=1) return v[i-1]+1;
    }
    return v.back()+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++)cin>>v[i];
    sort(v.begin(),v.end());
    cout<<getNum();
}
