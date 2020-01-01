#include<bits/stdc++.h>
using namespace std;
vector<int>v;

void getNum()
{
    for(int i=2;i<(int)1e9;i*=2)
        v.push_back(i);
}

bool isTrue(int k)
{
    for(auto i:v)
        if(k==i) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    
    getNum();
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        if(!isTrue(k)) cout<<"Gazua\n";
        else cout<<"GoHanGang\n";
    }
}
