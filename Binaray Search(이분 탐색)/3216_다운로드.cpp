#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,int>> music;

bool is_possible(int mid)
{
    for(int i=0;i<N;i++)
    {
        if(mid<music[i].second)return false;
        mid+=music[i].first-music[i].second;
    }
    return true;
}

int main()
{

    cin>>N;
    for(int i=0;i<N;i++)
    {
        int D,V;
        cin>>D>>V;
        music.push_back(make_pair(D,V));
    }

    int left=0,right=(int)1e9,ret;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(is_possible(mid))
        {
            ret=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ret;
}
